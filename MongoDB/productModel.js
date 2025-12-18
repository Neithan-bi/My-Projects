const mongoose = require('mongoose');

(async () => {
  try {
    // use correct default port 27017 unless you intentionally run Mongo on 27107
    await mongoose.connect('mongodb://localhost:27017/productDatabase');

    const productSchema = new mongoose.Schema({
      name: { type: String, required: true, minlength: 2, maxlength: 50 },
      price: { type: Number, required: true, min: 0 },
      category: { type: String, enum: ['Electronics', 'Clothing', 'Books', 'Food'] },
      inStock: { type: Boolean, default: true },
      tags: [String],
      createdAt: { type: Date, default: Date.now }
    });

    const Product = mongoose.model('Product', productSchema);

    const validProduct = await Product.create({
      name: 'Smartphone',
      price: 599.99,
      category: 'Electronics',
      tags: ['tech', 'gadget']
    });
    console.log('Valid product saved:', validProduct);

    try {
      const invalidProduct = new Product({
        name: 'X',        // Too short
        price: -10,       // Negative price
        category: 'Invalid' // Not in enum
      });
      await invalidProduct.save();
      console.log('Invalid product saved (this should not happen)');
    } catch (validationErr) {
      console.log('Validation errors:', validationErr.errors || validationErr.message);
    }
  } catch (err) {
    console.error(err);
  } finally {
    await mongoose.disconnect();
  }
})().catch(console.error);
