import java.util.*;

class Student
{
  public int Rno;
  public String Name;
  public int Age;
  public int Marks;

  public static int Generator;

  static
  {
    Generator = 0;
  }

  public Student()
  {

  }

  public Student(String str, int X, int Y)
  {
    this.Rno = ++Generator;
    this.Name = str;
    this.Age = X;
    this.Marks = Y;
  }

  public void Display()
  {
    System.out.println(this.Rno + " " +this.Name + " " + this.Age + " " + this.Marks);
  }
}

class Queries
{
  public LinkedList <Student> lobj;

  public Queries()
  {
    lobj = new LinkedList <Student> ();
  }

    // insert into table student values(______, _______, _______);
  public void InsertIntoTable(String name, int age, int marks)
  {
    Student sobj = new Student(name,age,marks);
    lobj.add(sobj);
  }

  // select * from student
  public void SelectFrom()
  {
    System.out.println("Records from the student table are : ");

    for(Student sref : lobj)
    {
      sref.Display();
    }
  }

  // select * from student where Rno = 11
  public void SelectFrom(int no)
  {
    System.out.println("Records from the student table are : ");

    for(Student sref : lobj)
    {
      if(sref.Rno == no)
      {
        sref.Display();
        break;
      }
    }
  }

    // select * from student where Name = 'Rahul'
  public void SelectFrom(String str)
  {
    for(Student sref : lobj)
    {
      if(str.equals(sref.Name))
      {
        sref.Display();
        break;
      }
    }
  }

  // delete  from student where RNo = 2
  public void DeleteFrom(int no)
  {
    int i = 0;

    for(Student sref : lobj)
    {
      if(sref.Rno == no)
      {
        lobj.remove(i);
        break;
      }
      i++;
    }
  }

  //update student set name = pranav where rno = 4
  public void update_name(String str,int no)
  {
    int i = 0;
    for(Student sref : lobj)
    {
      if(sref.Rno == no)
      {
        sref.Name = str;
        break;
      }
      i++;
    }
  }

  //select rno from student
  public void select_rno()
  {
    for(Student sref : lobj)
    {
      System.out.println(sref.Rno);
    }
  }

   //select name from student
  public void select_name()
  {
    for(Student sref : lobj)
    {
      System.out.println(sref.Name);
    }
  }

   //select age from student
  public void select_age()
  {
    for(Student sref : lobj)
    {
      System.out.println(sref.Age);
    }
  }

  //select marks from student
  public void select_marks()
  {
    for(Student sref : lobj)
    {
      System.out.println(sref.Marks);
    }
  }

  // select MAX(marks) from student
  public int Aggregate_Max()
  {
    Student temp = lobj.get(0);
    int iMax = temp.Marks;

    for(Student sref : lobj)
    {
      if(sref.Marks > iMax)
      {
        iMax = sref.Marks;
      }
    }
    return iMax;
  }

  // select MIN(marks) from student
  public int Aggregate_Min()
  {
    Student temp = lobj.get(0);
    int iMin = temp.Marks;

    for(Student sref : lobj)
    {
      if(sref.Marks < iMin)
      {
        iMin = sref.Marks;
      }
    }
    return iMin;
  }

  // select SUM(marks) from student
  public int Aggregate_Sum()
  {
    int iSum = 0;

    for(Student sref : lobj)
    {
      iSum = iSum + sref.Marks;
    }
    return iSum;
  }

  // select AVG(marks) from student
  public float Aggregate_Avg()
  {
    int iSum = 0;

    for(Student sref : lobj)
    {
      iSum = iSum + sref.Marks;
    }
    return (iSum / (lobj.size()));
  }
}
