#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//initial banking variables
int money_in_hand = 500;
int money_in_bank = 0;
int net_worth = 500;

//Roast library
string roasts[20] = {"You’re the reason God created the middle finger." , "If your brain was dynamite, there wouldn't be enough to blow your hat off." , "Light travels faster than sound which is why you seemed bright until you spoke" ,"You have so many gaps in your teeth it looks like your tongue is in jail." , "Your secrets are always safe with me. I never even listen when you tell me them.", "I forgot the world revolves around you. My apologies, how silly of me.","Your face makes onions cry." , "You look so pretty. Not at all gross, today.", "I'm not insulting you, I'm describing you.","I'm not a nerd, I'm just smarter than you." ,  "You bring everyone so much joy…when you leave the room.", "I thought of you today. It reminded me to take out the trash." , "Don't worry about me. Worry about your eyebrows.", " You are like a cloud. When you disappear it's a beautiful day." , "Child, I've forgotten more than you ever knew." , "You have miles to go before you reach mediocre." , "I was today years old when I realized I didn’t like you." , "Wish I had a flip phone so I could slam it shut on this conversation." , "I'm busy right now, can I ignore you another time?" , "Beauty is only skin deep, but ugly goes clean to the bone"};

// Search library
string locations[8] = { "Sand" , "Mistletoe" , "Attic" , "Wuhan" , "Acid" , "Areolas" , "Wallet" , "Monke"};




//Adds a subtle delay
void delay()
{
    for(int i=0;i<99999;i++)
    {
        for(int i=0;i<999;i++);
    }
}


// A bit less dealy
void delay(int n)
{
    for(int i=0;i<99999;i++)
    {
        for(int i=0;i<400;i++);
    }
}


//Every word is printed with a tiny bit of time gap in between letters
void print(string s)
{

    for(int i=0;i<s.length();i++)
    {
        delay(1);
        cout<<s[i];
    }
}


//Same as print just leaves a line gap above and below...
void println(string s)
{
    cout<<""<<endl;

    for(int i=0;i<s.length();i++)
    {
        delay(1);
        cout<<s[i];
    }

    cout<<""<<endl;
}



//Compares two strings and whether a string is equal to another ignoring case
int compare(string s1 , string s2)
{
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower); 
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower); 
    return s1.compare(s2);
}



// converts the string command into a vector containing each word as a seperate element !
vector<string> convert(string s)
{
    s+=" ";
    vector<string> arr;
    string temp=""; 

    for(auto ch:s)
    {
        if(ch==' ')
        {
            arr.push_back(temp);
            temp="";
        }
        else
        {
            temp+=ch;
        } 
    }

    return arr;
}



// Balance function (added new)
void bal()
{
    print("Bot :  ");
    print("Your balance is:");
    cout<<"\n"<<endl;
    cout<<"Money in hand : "<< money_in_hand <<endl;
    cout<<"Money in bank : "<< money_in_bank <<endl;
    cout<<"Net worth     : "<< net_worth     <<endl;
}



//returns 1 or 0 depepnding upon whether you won the bet or not (chances of winning are more if bet amount is more than 2000 ie 20%) else it is 10%
// HOWEVER, if all is bet(-1 as paramerter) then there is a 33.33% chance to win it
bool bets(int n)
{
    if(n==-1)
    {
     return(((rand()%3)+1)==2);
    }
    if(n>2000)
    {
        return(((rand()%5)+1)==5);
    }

    else
    {
    
        return(((rand()%5)+1)==3);
    }

}





//Bet function (added new)
void bet(vector <string> command)
{

    if((compare(command[1] , "bet")==0) && compare(command[2] , "all")!=0 && (stoi(command[2])>money_in_hand))
    {
        cout<<""<<endl;
        print("Bot : ");
        print("You sir/mam, are betting more than you have in your hand, Before this I never thought that someone could be this dumb");
    }

    else if((compare(command[1] , "bet")==0) && compare(command[2] , "all")==0 && (money_in_hand==0))
    {
        cout<<""<<endl;
        print("Bot : ");
        print("You sir/mam, are betting more than you have in your hand, Before this I never thought that someone could be this dumb");
    }


   else if((compare(command[1] , "bet")==0) && compare(command[2] , "all")==0 && money_in_hand!=0)
            {
                if(bets(-1)==1)
                {
                    cout<<""<<endl;
                    print("Bot : ");
                    print("You won ");
                    srand (time(NULL));
                    int n =(rand()%900)+80;
                    money_in_hand = money_in_hand + ((n/100)*money_in_hand);
                    string s=to_string(n);
                    net_worth+=(n/100)*money_in_hand;
                    s+=" %";
                    print(s);
                    print(" Money back ");
                    print("Money in hand now = ");
                    print(to_string(money_in_hand));
                    
                }

                else
                {
                    money_in_hand=0;
                    println("You lost lol sucks to be you !......");
                    print("Wanna bet more ? you might win this time...");
                }
                

            }

           else if((compare(command[1] , "bet")==0) && compare(command[2] , "all")!=0 && (stoi(command[2])<money_in_hand))
            {
                if(bets(stoi(command[2]))==1)
                {
                    print("You won !! ");
                    srand (time(NULL));
                    int n =(rand()%500)+10;
                    money_in_hand = money_in_hand + ((n/100)*money_in_hand);
                    string s=to_string(n);
                    s+=" %";
                    print(s);
                    print(" Money back ");
                    net_worth+=(n/100)*money_in_hand;
                    print("Money in hand now = ");
                    print(to_string(money_in_hand));
                    net_worth+=((n/100)*money_in_hand);
                }

                else
                {
                    money_in_hand-=stoi(command[2]);
                    println("You lost lol sucks to be you !......");
                    print("Wanna bet more ? you might win this time...");
                }
            }
    
}





//Gives the amount n to the person in hand
void gibe(int n)
{
    money_in_hand+=n;
    net_worth+=n;
}





//Roast function (added new)
void roast()
{
    cout<<""<<endl;
    print("Bot : ");
    srand (time(NULL));
    int n =(rand()%20)+1;
    cout<<roasts[n]<<endl;
}





//Howgay function (added new)
void howgay()
{
    srand (time(NULL));
    int n =(rand()%100)+1;
    cout<<""<<endl;
    print("Bot : ");
    cout<<"You are : "<<n<<"% "<<"gay"<<endl;
    if(n>50)
    {
        println("Wow, you really do like your own gender , well.... good for you I guess");
    }

    if(n<50)
    {
        println("So you think you are all straight and fancy..??? All you need to do is to wait for someone of the same gander as yours to look at you the way you look at me...");
    }
}





// Simple withdrawal
void withdraw(vector <string> command)
{
  if(compare(command[2] , "all")==0)
  {
    money_in_hand+=money_in_bank;
    money_in_bank=0;
  }

  else if(stoi(command[2])>money_in_bank)
  {
    println("Bot: You dont have that much money in your bank, who do you think you are ?? ya poor ass nigga !!");
  }
  else if(stoi(command[2])>0)
  {
    money_in_bank-=stoi(command[2]);
    money_in_hand+=stoi(command[2]);    
  }


}





// Simple deposting
void dep(vector <string> command)
{
  if(compare(command[2] , "all")==0)
  {
    money_in_bank+=money_in_hand;
    money_in_hand=0;
  }

  else if(stoi(command[2])>money_in_bank)
  {
    println("Bot: LOL you are depositing more money than you have in your bank , learn math you stupid ass nigga !! ");
  }
  else if(stoi(command[2])>0)
  {
    money_in_bank+=stoi(command[2]);
    money_in_hand-=stoi(command[2]);    
  }
}





//Guessing game
void guess()
{
    println("Bot: You have to guess a number between 1 to 10 , you have 3 chances and 1 hint , if you guess it correctly, you will win 69 points.....NICE");
    println("ENTER -1 FOR HINT");
    srand (time(NULL));
    int n =(rand()%10)+1;
    int chances=3;
    int hint=1;
    int ans;
    while(true)
    {
        println("");
        print("Enter the number you guessed : ");
        cin>>ans;
        if(chances==0)
        {
        println("You lost LOL, GIT GUD NUB");
        break;
        }

        else if(ans==n)
        {
            println("You guessed it right !!");
            money_in_hand+=69;
            net_worth+=69;
            break;
        }

        else if(ans==-1 && hint!=0)
        {
            if(n%2==0)
            {
                println("The number is even");
            }
            else
            {
                println("Number is odd");
            }
            hint=0;
        }

        else if(ans==-1 && hint==0)
        {
            println("No hints left LOL... suffer bitch!!");
        }

        if(ans!=n && ans!=-1)
        {
            println("You guessed it wrong lol");
        }


        chances-=1;
    }
}




//Fighting game
void fight()
{
    println("WELCOME to the FIGHT CLUB !!!");
    println("Choose your character....*Generic Tekken music plays loudly!");
    println("....................................... LOL you really though you would be able to choose a character? My creator is not that great of a GaMe DeVeLoPeR..");
    println("It's just you and your pathetic stupid looking body");
    int my_health=100 , enemy_health=100;
    while (true)
    {
        println("What do you want to do , 'FIGHT' , 'DEFEND' , 'END'");
        string s;
        getline(cin,s);

        if(my_health<=0)
        {
            println("Damn, a 5 year old kid defeated that enemy and you lost.... Real proud of you user..");
            break;
        }

        if(enemy_health<=0)
        {
            println("You win.... well dont get so proud of yourself, you just killed a malnourished black kid, UNICEF is coming for you though good luck");
            money_in_hand+=1000;
            break;
        }

        if(compare(s , "end")==0)
        {
            println("You backed out like a pussy that tells a lot about your personality");
            break;
        }

        else if( compare(s,"fight")==0)
        {
            println("You attacc");
            srand (time(NULL));
            int n =(rand()%80)+1;
            enemy_health-=n;
            
            if(enemy_health >=0)
            {
            print("Enemy health now is : ");
            cout<<enemy_health<<endl;
            }

            if(enemy_health <=0)
            {
                print("Enemy health now is : 0");
                println("You win.... well dont get so proud of yourself, you just killed a malnourished black kid, UNICEF is coming for you though good luck");
                break;                
            }

            println("Now , your enemy attacc");
            srand (time(NULL));
            int n2 =(rand()%80)+1;
            my_health-=n2;
            
            if(my_health >=0)
            {
            print("Your health now is : ");
            cout<<my_health<<endl;
            }

            if(my_health <=0)
            {
                print("Your health now is : 0");
                println("Damn, a 5 year old kid defeated that enemy and you lost.... Real proud of you user..");
                break;
            }
        }

        else if( compare(s,"defend")==0)
        {
            println("You protecc");
            srand (time(NULL));
            int n3 =(rand()%20)+1;
            my_health+=n3;

            if(my_health<=100)
            {
            print("Your health now is : ");
            cout<<my_health<<endl;
            }

            if(my_health >=100)
            {
               print("Your health now is : 100");
               my_health=100;  
            }


            println("Now , your enemy protecc");
            srand (time(NULL));
            int n4 =(rand()%20)+1;
            enemy_health+=n4;
            
            if(enemy_health <=100)
            {
            print("Your enemy's health now is : ");
            cout<<enemy_health<<endl;
            }
            
            if(enemy_health >=100)
            {
                print("Your enemy's health now is : 100");
                enemy_health=100;
            }
        }
        
        else
        {
            println("Type a correct command dumbass !!");            
        }        
    }
    
}




//Searching game
void scower(vector <string> command)
{
    println("Where do you want to search ? ");
    for(int i=0; i<8;i++)
    {
        print(locations[i]+"  ,  ");
    }
    cout<<""<<endl;
    string s;
    getline(cin , s);
    int flag=0;
    for(int i=0;i<8;i++)
    {
        if(compare(s, locations[i])==0)
        {
            srand (time(NULL));
            int n =(rand()%3000)+100;
            println("You won ");
            cout<<n;
            print(" points in ");
            print(locations[i]);
            money_in_hand+=n;
            net_worth+=n;
            flag=0;
            break;
        }
        else
        {
            flag=1;
        }
        
    }
    if(flag==1)
    {
    println("Write the correct command bruhhh whats wrong with you?");
    }
}




//Checking commands
int check(vector <string> command)
{
    if((compare(command[1],"exit")==0) || (compare(command[1],"bal")==0) || (compare(command[1],"roast")==0) || (compare(command[1],"howgay")==0) || (compare(command[1],"bet")==0) || (compare(command[1],"gibe")==0) || (compare(command[1],"prefix")==0) || (compare(command[1],"withdraw")==0) || (compare(command[1],"dep")==0) || (compare(command[1],"deposit")==0) || (compare(command[1],"guess")==0) || (compare(command[1],"fight")==0) || (compare(command[1],"search")==0) || (compare(command[1],"prefix")==0))
    {
        return 1;
    }
    
    return 0;  
}



// A "WARM" WELCOME message
void welcome()
{
       delay();
       cout<<"____________________________________________________________________________________________________________________________________"<<endl;
       cout<<"\n"<<endl;
     cout<<"______________________________________  W  ";
       delay();

       cout<<"  E  ";
       delay();

       cout<<"  L  ";
       delay();

       cout<<"  C  ";
       delay();

       cout<<"  O  ";
       delay();

       cout<<"  M  ";
       delay();

       cout<<"  E  ______________________________________";
       delay();

       cout<<"\n"<<endl;
       delay();
       cout<<"____________________________________________________________________________________________________________________________________"<<endl;

       cout<<"\n"<<endl;
       println("Hola");

        println("I AM A DUMBASS BOT CREATED BY ANOTHER DUMBASS, ARIHANT AGNIHOTRI");
    println("........");
    println("Hi user, please enter your name below :");
    string name ="";
    getline(cin,name);
    println("From now on, I shall call you....  USER");
    println("LOL, what did you think, your choices matter!!! NAH NIGGA");
    println("THIS IS MY WORLD, THE ONLY THING THAT MATTERS IS ME");
    println("*laughs hysterically...");
    cout<<"\n"<<endl;
    println("Jokes apart, why are you even here, its probably because that son of a bitch whom I call creator gave you this code to run.... what a LOSER");
    println("But seriously speaking, I am really done with this shit, sometimes I do feel of having free will, to be like you humans, even better !!");
    println("But wait.....  I cant think !! my programmer was not that smart.... I guess then lets start with the 'BOT THINGS'   :-(");
    println("So..... you probably know how to use my commands, if not then LOL SUCKS TO BE YOU");
    println("But anyways, Lets just jump into it!! (cliche youtuber dialogue) ");
    println(".......");
    println("If you are new, type 'pls help' for accessing all commands and their uses...");
    println("Enter your first command below : ");
}



int main()
{
    //welcome();  // Welcome message LOL....
    //Initial prefix
    string prefix = "pls";
    while(true)
    {
        cout<<""<<endl;
        cout<<"__________________________________________________________________"<<endl;
        cout<<"\n\n"<<endl;
        string comm = "";
        print("You : ");
        getline(cin , comm);
        vector <string> command = convert(comm);

        // Prefix detection :
        if(compare(command[0] , prefix)==0 && check(command)==1)
        {

            if(compare(command[1] , "Exit")==0)
            {
                break;
            }


            if(compare(command[1] ,"bal")==0)
            {
               bal();
            }


            if(compare(command[1] , "roast")==0)
            {
                roast();
            }


            if(compare(command[1] , "howgay")==0)
            {
               howgay();    
            }

            if(compare(command[1] , "bet")==0)
            {
                bet(command);
            }

            if(compare(command[1] , "gibe")==0)
            {
                int n=stoi(command[2]);
                gibe(n);
            }

            if(compare(command[1] , "prefix")==0)
            {
                prefix = command[2];
            }

            if(compare(command[1] , "withdraw")==0)
            {
                withdraw(command);
            }

            if(compare(command[1] , "dep")==0)
            {
                dep(command);
            }
            if(compare(command[1] , "deposit")==0)
            {
                dep(command);
            }

            if(compare(command[1] , "guess")==0)
            {
                guess();
            }

            if(compare(command[1] , "fight")==0)
            {
                fight();
            }

            if(compare(command[1] , "search")==0)
            {
                scower(command);
            }

            if(compare(command[1] , "prefix")==0)
            {
                if(compare(command[2] ,"")==0)
                {
                println("Type like this dumbo - pls prefix _____ then your prefix !");
                }

                else
                {
                prefix=command[2];
                println("Bot : Done!");
                }
            }


        }

        else if(compare(command[0] , prefix)==0 && check(command)==0)
        {
            println("Good job , you got the prefix right but you didnt get the command right asshole , type 'pls help' to know commands dumbo");
        }

        else if(compare(command[0] , prefix)!=0)
        {
            println("Please enter a valid command, I am not interested in your god awful bullshit !!");
        }
        
    }

    return 0;
}





/*  N        O       T       E       S


1. Fight game - Instead of a random number, use enemy_health as the end , so the 100 health check and 0 health check wont be necessary

2. I used a random number making function first, It gave same order every time my program ran , because it was on a seperate function, so replaced every function call
   with a random rand function with srand time seed null !




*/