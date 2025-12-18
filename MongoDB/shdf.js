const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost:27017/mydatabase', {
    useNewUrlParser: true,
    useUnifiedTopology: true
})
.then(() => {
    console.log('Connected to MongoDB');
})
.catch((err) => {
    console.error('Connection error', err);
});
const authorSchema = new mongoose.Schema({
    name: String,
    age: Number, 
});
const bookSchema = new mongoose.Schema({
    title: String,
    pages: Number,
    author : { type: mongoose.Schema.Types.ObjectId, ref: 'Author' }
});
