const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const path = require('path');
const app = express();
const port = 3000;
// Connect to MongoDB
mongoose.connect('mongodb://localhost:27017/FirstTry', {
 useNewUrlParser: true,
 useUnifiedTopology: true
}).then(() => console.log('MongoDB connected'))
 .catch(err => console.log(err));
// Middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(express.static(__dirname));
app.set('view engine', 'ejs');
app.set('views', __dirname);
// Define a Mongoose schema and model
const itemSchema = new mongoose.Schema({
 name: String,
 description: String
});
const Item = mongoose.model('Item', itemSchema);
// Routes
app.get('/', async (req, res) => {
 const items = await Item.find();
 res.render('exp9', { items });
});
app.post('/items', async (req, res) => {
 const newItem = new Item(req.body);
 await newItem.save();
 res.redirect('/');
});
app.put('/items/:id', async (req, res) => {
 await Item.findByIdAndUpdate(req.params.id, req.body);
 res.send('Item updated');
});
app.delete('/items/:id', async (req, res) => {
 await Item.findByIdAndRemove(req.params.id);
 res.send('Item deleted');
});
// Start the server
app.listen(port, () => {
 console.log(`Server is running on http://localhost:${port}`);
});