#include<iostream>
#include<climits>
#include<string>
#include<fstream>
using namespace std;

string encode(string pass){
    for(int i=0;i<pass.length();i++){
        pass[i]=pass[i]+2;
    }
    return pass;
}
string decode(string pass){
    for(int i=0;i<pass.length();i++){
        pass[i]=pass[i]-2;
    }
    return pass;
}
class temp{
    string username  , password , Email;
    string searchName , searchPassword , searchEmail;
     
    fstream file;
    public:
    void login(){
        int count=3;
        while(count>0){
        
        cout<<"-----------------------------------LOGIN PAGE----------------------------------"<<endl;
        bool found=false;
         bool correctPassword=false;

        cout<<"Enter your username:: ";
        getline(cin , searchName);
        cout<<"\nEnter you Password:: ";
        getline(cin , searchPassword);

        file.open("loginData.txt" , ios::in); // read mode
        while(getline(file , username , '*')){
            getline(file , Email , '*');
            getline(file , password , '\n');
          found=false;
          correctPassword=false;

            if(username==searchName){
                found=true;

                password=decode(password); 
                // decode the password before comparing
                if(password==searchPassword){
                    correctPassword=true;
                }
                else{
                    cout<<"Incorrect Password !"<<endl;
                    break;
                }
            }
           
        }

        if(!found){
            if(!correctPassword){
                cout<<"Incorrect username or password !"<<endl;
                
               
            }
           else cout<<"Username not found !"<<endl;
           count--;
        }
        else if(!correctPassword){
            cout<<"Incorrect Password !"<<endl;
            count--;
        }
        else{
            cout<<"Login successful !"<<endl;
            cout<<"username:: "<<username<<endl;
            cout<<"Email:: "<<Email<<endl;
            
        }
    }
        file.close();

    

    };
    void signUp(){
        cout<<"-----------------------------------SIGN UP PAGE----------------------------------"<<endl;
        cout<<"\nEnter your username:: ";
        getline(cin , username);
        file.open("loginData.txt" , ios::in);
        bool exist=false;
        string u,p,e;
        while(getline(file , u , '*')){
            getline(file , e , '*');
        getline(file , p );
        if(u==username){
            exist=true;
            
            break;
        }
    }
    file.close();
    if(exist){
        cout<<"Username already exist !"<<endl;
        return;
    }
exist=false;

file.open("loginData.txt" , ios::in);
        cout<<"\nEnter you Email Address:: ";
        getline(cin , Email);
        while(getline(file , u , '*')){
            getline(file , e , '*');
        getline(file , p );
        if(e==  Email){
            exist=true;
            
            break;
        }
    }
    if(exist){
        cout<<"Email already exist !"<<endl;
        return;
    }


        cout<<"\nEnter your password:: ";
        getline(cin , password);
        password=encode(password);
       
    file.close();
         // encode the password before storing

        file.open("loginData.txt" , ios::out| ios::app); // data will be added and always added at the end of the file (and out means write mode)
        file<<username<<'*'<<Email<<'*'<<password<<endl;// file mein username email and pass daal diya
        file.close();
    };
    void forgetPassword(){
        bool found=false;
        cout<<"------------------------------------FORGET PASSWORD PAGE----------------------------------"<<endl;
        cout<<"\nEnter you Username:: ";
        getline(cin , searchName);
        cout<<"\nEnter you Email Address:: ";
        getline(cin , searchEmail);
        file.open("loginData.txt" , ios::in);
        while(getline(file , username , '*')){
            getline(file , Email , '*');
        getline(file , password );
            if(username==searchName){
                found=true;
                if(Email==searchEmail){
                    cout<<"Account found !"<<endl;
                    password=decode(password); // decode the password before displaying
                    cout<<"your passwords is:: "<<password<<endl;
                    break;
                }
                else{
                    cout<<"Incorrect Email Address !"<<endl;
                    break;
                }
            }
           
        }
         if(!found){
            cout<<"Username not found !"<<endl;
        }
            file.close();
    }
};

 
int main(){
     int choice=0;

    
    
    cout<<"\n-------------WELCOME TO THE REGISTRATION AND LOGIN PAGE-------------";
    cout<<"\n Choose From the following options:";
    cout<<"\n 1. Login";
    cout<<"\n 2. Sign Up";
    cout<<"\n 3. Forget Password";
    cout<<"\n 4. Exit";cout<<endl;
   
        cout<<"\nEnter you choice:: ";
    cin>>choice;
    cin.ignore(INT_MAX, '\n');
        switch(choice){
        case 1:{
            temp t;
            t.login();
        break;
        }
        case 2:{
            temp t;
            t.signUp();
           break;
    }
      case 3:{
            temp t;
            t.forgetPassword();
           break;
    }
     case 4:{
            return 0;
           break;
    }
    default:{
        cout<<"Invalid choice"<<endl;
   

}
        }
  
 }