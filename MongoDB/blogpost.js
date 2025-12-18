const mongoose = require('mongoose');

async function main() {
    try {
        await mongoose.connect('mongodb://localhost:27017/FirstTry', {
            useNewUrlParser: true,
            useUnifiedTopology: true
        });

        // Define Author Schema
        const authorSchema = new mongoose.Schema({
            name: String,
            bio: String
        });

        // Define Post Schema
        const postSchema = new mongoose.Schema({
            title: String,
            content: String,
            author: { type: mongoose.Schema.Types.ObjectId, ref: 'Author' }
        });

        const Author = mongoose.model('Author', authorSchema);
        const Post = mongoose.model('Post', postSchema);

        // Create an author
        const author = new Author({
            name: 'John Doe',
            bio: 'A passionate writer'
        });

        const savedAuthor = await author.save();

        // Create a post
        const post = new Post({
            title: 'My First Blog Post',
            content: 'This is the content of my first blog post.',
            author: savedAuthor._id
        });

        const savedPost = await post.save();

        // Find the post and populate author details
        const populatedPost = await Post.findById(savedPost._id).populate('author').exec();
        console.log(populatedPost);
    } catch (err) {
        console.error(err);
    } finally {
        await mongoose.disconnect();
    }
}

main().catch(console.error);
