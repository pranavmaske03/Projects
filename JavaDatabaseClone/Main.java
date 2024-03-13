import java.util.*;

class DBMS extends Queries
{
  public void StartDBMS()
  {
    System.out.println("Marvellous DBMS started succesfully...");
    System.out.println("Table Schema created succesfully...");

    String Query;
    String Tokens[];

    Scanner sobj = new Scanner(System.in);
    int TokensCount = 0;

    while(true)
    {
      System.out.print("Marvellous DBMS : ");
      Query = sobj.nextLine();

      Tokens = Query.split(" ");

      TokensCount = Tokens.length;

      if(TokensCount == 1)
      {
          if("exit".equals(Tokens[0]))
          {
              System.out.println("Thank you for using Marvellous DBMS...");
              break;
          }
      }
      else if(TokensCount == 2)
      {
    
      }
      else if(TokensCount == 3)
      {}
      else if(TokensCount == 4)
      {
        if("select".equals(Tokens[0]))
        {
          if("*".equals(Tokens[1]))
          {
            SelectFrom();
          }
          else if("rno".equals(Tokens[1]))
          {
            select_rno();
          }
          else if("name".equals(Tokens[1]))
          {
            select_name();
          }
          else if("age".equals(Tokens[1]))
          {
            select_age();
          }
          else if("marks".equals(Tokens[1]))
          {
            select_marks();
          }
        }
      }      
      else if(TokensCount == 5)
      {
        if("select".equals(Tokens[0]))
        {
          if("MAX".equals(Tokens[1]))
          {
            System.out.println("Maximum marks are : "+Aggregate_Max());
          }
          else if("MIN".equals(Tokens[1]))
          {
            System.out.println("Minimum marks are : "+Aggregate_Min());
          }
          else if("AVG".equals(Tokens[1]))
          {
            System.out.println("Average marks are : "+Aggregate_Avg());
          }
          else if("SUM".equals(Tokens[1]))
          {
            System.out.println("Sum of marks are : "+Aggregate_Sum());
          }
        }
      }
      else if(TokensCount == 6)
      {}      
      else if(TokensCount == 7)
      {
        if("insert".equals(Tokens[0]))
        {
          InsertIntoTable(Tokens[4], Integer.parseInt(Tokens[5]), Integer.parseInt(Tokens[6]));
        }
        else if("delete".equals(Tokens[0]))
        {
          DeleteFrom(Integer.parseInt(Tokens[6]));
        }
      }
      else if(TokensCount == 10)
      {
        if("update".equals(Tokens[0]))
        {
          update_name(Tokens[5],Integer.parseInt(Tokens[9]));
        }
      }
    }

  }
}

class Main
{
  public static void main(String arg[])
  {
    DBMS obj = new DBMS();
    obj.StartDBMS();
  }
}

// Insert Query
// Insert into student values Rahul 23 67
//    0    1     2        3     4    5  6
// No of tokens : 7

// select query
// select * from student
//    0   1   2    3
// No of tokens : 4

// delete from student where Rno = 4
//  0      1      2      3    4  5 6
// No of tokens : 7

// select Max Age from student
//  0     1     2    3    4 
// No of tokens : 5

// select rno from student
//    0      1   2    3

// select name from student
// select age from student
// select marks from student 