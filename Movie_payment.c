using System;

namespace Movie_reservation
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Are you an adult or a teenager?");
            Console.WriteLine("If you're an adult, press 1.");
            Console.WriteLine("If you're an teenager, press 2.");
           
            //money = int.Parse(Console.ReadLine());
            int person;
            person = int.Parse(Console.ReadLine());
            if (person == 1)  //adult
            {
                Console.WriteLine("The adult fare is 9,000 won.");
                Console.WriteLine("Input Number of adults  => ex. 3, 4, ...");
                int adultsNum;
                adultsNum = int.Parse(Console.ReadLine());
                int adultFare = adultsNum * 9000;
                Console.WriteLine("Pay {0} won in total.", adultFare);
                Console.WriteLine("Put the money in.");

                int money;
                money = int.Parse(Console.ReadLine());
                int change = adultFare - money;
                if (money < adultFare) //돈 더 넣어라
                {
                    Console.WriteLine("Amount entered : {0}won. put {1}won more", money, change);
                    
                }
                else if (money >= adultFare) //돈 
                {
                    Console.WriteLine("{0} adult tickets have been purchased.", adultsNum);
                    Console.WriteLine("The balance is {0} won.", Math.Abs(change));
                }
            }
            else if(person == 2)  //teenager
            {
                Console.WriteLine("The teenager fare is 7,000 won.");
                Console.WriteLine("Input Number of teenager  => ex. 3, 4, ...");
                int teensNum;
                teensNum = int.Parse(Console.ReadLine());
                int teenFare = teensNum * 7000;
                Console.WriteLine("Pay {0} won in total.", teenFare);


                int money;
                money = int.Parse(Console.ReadLine());
                int change = teenFare - money;
                if (money < teenFare) //돈 더 넣어라
                {
                    Console.WriteLine("Amount entered : {0}won. put {1}won more", money, change);

                }
                else if (money >= teenFare) //돈 
                {
                    Console.WriteLine("{0} teenager tickets have been purchased.", teensNum);
                    Console.WriteLine("The balance is {0} won.", Math.Abs(change));
                }
            }
            
        }
    }
}

