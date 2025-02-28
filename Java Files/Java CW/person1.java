//parent class//
 class person {
    String name;
    int age;
    int mobile ;

    public person(){
        this.name="bhuvi";
        this.age=19;
        this.mobile=1234567891;
    }
 
    public person(String name, int age ,int mobile) {
       this.name=name;
       this.age=age;
       this.mobile =mobile ;
    }
 

  
   public void  display(){
    System.out.println("name is"+name +"age is"+age+"mobile"+mobile);

   }
}

//child 1//
public class employee extends person{
    String organisation;
    int empid;
    public employee(String name, int age ,int mobile,String organisation,int empid){
        super(name,age,mobile);
        this.organisation=organisation;
        this.empid=empid;

    }
    public void display1(){
        super.display();
        System.out.println("organisation"+organisation+ "empid is"+empid);
    }
    // child 2//
    public class student extends person{
        String name1 ;
        int id;
        public student( String name,int age,int mobile,String name1, int id){
            super(name,age,mobile);

            this.name1=name1;
            this.id=id;
        }
        
            
        }
        public void display2(){
            super.display();
            System.out.println("name is"+name1+"id is"+id);
            
}
}

public class person1{
    public static void main(String[] args) {
      person bhuvi=new person("pintu",19,234567);
      bhuvi.display();
      student s1 =new student()
         
    }
}
  

 