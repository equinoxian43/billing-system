#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
    int pcode;
    float price;
    float dis;
    string pname;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void rem();
    void list();
    void receipt();
    void edit();

};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t\t\t                   \n";
    cout<<"\t\t\t\t\t\t                   \n";
    cout<<"\t\t\t\t Supermarket main menu \n";
    cout<<"\t\t\t\t\t\t                   \n";
    cout<<"\t\t\t\t\t\t                   \n";
    cout<<"\t\t\t\t\t\t| 1)Administrator    |\n";
    cout<<"\t\t\t\t\t\t                   \n";
    cout<<"\t\t\t\t\t\t| 2)Buyer            |\n";
    cout<<"\t\t\t\t\t\t                   \n";
    cout<<"\t\t\t\t\t\t| 3) Exit           |\n";
    cout<<"\n\t\t\t Please select!";
    cin>>choice;

    switch(choice){
        case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter email \n";
        cin>>email;
        cout<<"\t\t\t Enter password \n";
        cin>>password;

        if(email=="amanlp4310@gmail.com" && password=="bias@123"){
            administrator();
        }
        else{
            cout<<"Invalid email/password";
        }
        break;

        case 2:
        {
            buyer();
        }

        case 3:
        {
            exit(0);

        }

        default:
        {
            cout<<"Please select from the given options";
        }

    }
goto m;
}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\n\n\t\t\t| 1)Add the product    |";
    cout<<"\n\n\n\t|                          |";
    cout<<"\n\n\n\t\t\t| 2)Modify the product |";
    cout<<"\n\n\n\t|                          |";
    cout<<"\n\n\n\t\t\t| 3)Delete the product |";
    cout<<"\n\n\n\t|                          |";
    cout<<"\n\n\n\t\t\t| 4)Back to main menu  |";

    cout<<"\n\n\t Please enter your choice";
    cin>>choice;

    switch(choice){
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
        rem();
        break;

        case 4:
        menu();
        break;

        default:
        cout<<"Invalid choice"<<endl;
    }
    goto m;
}

void shopping::buyer(){
    m:
    int choice;
     cout<<"\n\n\n\t\t\t Buyer";
    cout<<"\n\n\n\t\t\t| 1)Buy the product    |";
    cout<<"\n\n\n\t|                          |";
    cout<<"\n\n\n\t\t\t| 2)Go back            |";
    cout<<"\n\n\n\t Enter your choice :        ";
    cin>>choice;

    switch(choice){
        case 1:
        receipt();
        break;

        case 2:
        menu();
        break;

        default:
        cout<<"invalid choice";
    }
    goto m;    
}

void shopping::add(){
    m:
    fstream data;
    int c;
    int token;
    float p;
    float d;
    string n;

    cout<<"\n\n\n\t\t\t Add new product";
    cout<<"\n\n\n\t\t\t 1)product code of product";
    cin>>pcode;
    cout<<"\n\n\n\t\t\t| 2)Name of the product |";
    cin>>pname;
    cout<<"\n\n\n\t\t\t| 3)Price of the product |";
    cin>>price;
    cout<<"\n\n\n\t\t\t| 4)Discount on product  |";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==pcode){
                token++;
            }
             data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1)
    goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }

    cout<<"\n\n\t\t Record inserted !";
}

void shopping ::edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\n\t\t\t Modify the record";
    cout<<"\n\n\n\t\t\t 1)product code";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n File does not exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while (!data.eof())
        {
            if(pkey==pcode){
                cout<<"\n\t\t Product new code:";
                cin>>c;
                cout<<"\n\t Name of the product:";
                cin>>n;
                cout<<"\n\t Price:";
                cin>>p;
                 cout<<"\n\t Discount:";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited !";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("databse1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry!";
        }
        
    }

}


void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code";
    cin>>pkey;
    data.open("databse.txt",ios::in);
    if(!data){
        cout<<"File does not exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deletd successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("databse1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry!";
        }
        
    }
}

void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n";
    cout<<"Prono\t\t Name \t\t Price\n";
    cout<<"\n\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}

void shopping::receipt(){
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t RECEIPT";
    data.open("databse.txt",ios::in);
    if(!data){
        cout<<"empty database";
    }
    else{
        data.close();

        list();
         cout<<"\t\t\t\t\t\t                    \n";
         cout<<"\t\t\t\t Please place the order \n";
         cout<<"\t\t\t\t\t\t                    \n";
         do{
            cout<<"\n\n Enter Product code:";
            cin>>arrc[c];
            cout<<"\n\n Enter Product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes then press y else n";
            cin>>choice;
            }
            
         
         while(choice=='y');
         {
          cout<<"\n\n\t\t\t Receipt\n";
          cout<<"\nProduct NO. \t Product name \t qunatity \t Price \t amount \t amount with discount";

          for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<" "<<arrq[i]<<" "<<price<<" "<<amount<<" "<<dis;
                    
                }
                data>>pcode>>pname>>price>>dis;
            }
          }
          data.close(); 

         }
         cout<<"\n\n";
         cout<<"\n\n Total amount:"<<total;
    }
}



int main(){
    shopping s;
    s.menu();

}


