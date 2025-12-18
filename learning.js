const mongoose = require('mongoose');
mongoose.connect("mongodbd://localhost:27107")
.then(()=> console.log("Connected to MongoDB"))
.catch(err=> console.log(err));
const studSchema = new mongoose.Schema({
    name :String,
    dept:String,
    age:Number});
const Student = mongoose.model("Student,studSchema");
const addStudent = async()=>{
    await Student.create({
        name:"John",
        dept:"CS",
        age:21
    })
    console.log("Student Added");
};
const showStudents = async()=>{
    const students = await Student.find();
    console.log(students);
}
const run = async()=>{
    await addStudent();
    await showStudents();
    mongoose.disconnect();
};
run();

const mongoose = require('mongoose');
mongoose.connect("mongodb://localhost:27107")
.then(()=>console.log('Connected'))
.catch((err)=>console.log(err));
const studentSchema = new mongoose.Schema({
    name:String,
    dept,String,
    age:Number});
const Student = mongoose.model('Student',studentSchema);
const addStudent = async()=>{
    await Student.create({
        name:"Alice",
        dept:"Math",
        age:22
    })
    console.log("Student Added");
};
const showStudent = async()=>{
    await Student.find();
    console.log(students);
};
const run = async()=>{
    await addStudent();
        await showStudent();
            mongoose.disconnect();

};
run();