#include<bits/stdc++.h>
using namespace std;


class product                           //containing product id,category,name
{
    public:
    int product_id;
    string product_category,product_name;
};

class sold_product: public product      //inherited from product. Extra customer id,p_price
{
    public:
    int customer_id,price;
};

class bought_product: public product    //inherited from product. Extra buyer id,name,p_price
{
    public:
    int buyer_id,price;
    string buyer_name;
};

//variables:
int i,p,total_product,total_customer,total_buyer;
product pro[5];
sold_product sold[5];
bought_product bought[5];


//      ****         product part        ****
void read_product()
{
    ifstream pi("productIN.txt",ios::in);

    i=0;
    while(pi >> pro[i].product_id)      //reading all the products
    {
        pi>>pro[i].product_category>>pro[i].product_name;
        i++;
    }
    total_product=i;
}
void write_product()
{
    ofstream po("productOut.txt",ios::out);

    p=0;
    while(p<total_product)
    {
        po <<"Product ID: \t\t"<< pro[p].product_id << endl;
        po <<"Product Category: \t"<<pro[p].product_category<<endl;
        po <<"Product Name: \t\t"<<pro[p].product_name<<endl<<endl;
        p++;
    }
}

//      ****         customer part        ****
void read_customer()
{
    ifstream ci("customerIN.txt",ios::in);

    i=0;
    while(ci >>sold[i].product_id)      //reading all customer details
    {
        ci>>sold[i].product_category>>sold[i].product_name;
        ci>>sold[i].customer_id>>sold[i].price;
        i++;
    }
    total_customer=i;
}
void write_customer()
{
    ofstream co("customerOut.txt",ios::out);

    p=0;
    while(p<total_customer)
    {
        co <<"Product ID: \t\t"<< sold[p].product_id << endl;
        co <<"Product Category: \t"<<sold[p].product_category<<endl;
        co <<"Product Name: \t\t"<<sold[p].product_name<<endl;
        co <<"Customer ID: \t\t"<<sold[p].customer_id<<endl;
        co <<"Product Price: \t\t"<<sold[p].price<<endl<<endl;
        p++;
    }
}

//      ****         buyer part        ****
void read_buyer()
{
    ifstream bi("buyerIN.txt",ios::in);

    i=0;
    while(bi >>bought[i].product_id)
    {
        string c;
        bi >>bought[i].product_category>>bought[i].product_name;
        bi >>bought[i].buyer_id;
        getline(bi,c);      //to ignore the newline command
        getline(bi,bought[i].buyer_name);
        bi >>bought[i].price;
        i++;
    }
    total_buyer=i;
}
void write_buyer()
{
    ofstream bo("buyerOut.txt",ios::out);

    p=0;
    while(p<total_buyer)
    {
        bo <<"Product ID: \t\t"<<bought[p].product_id << endl;
        bo <<"Product Category: \t"<<bought[p].product_category<<endl;
        bo <<"Product Name: \t\t"<<bought[p].product_name<<endl;
        bo <<"Buyer ID: \t\t"<<bought[p].buyer_id<<endl;
        bo <<"Buyer Name: \t\t"<<bought[p].buyer_name<<endl;
        bo <<"Product Price: \t\t"<<bought[p].price<<" BDT"<<endl<<endl;
        p++;
    }
}


int main()
{
    read_product();
    write_product();

    read_customer();
    write_customer();

    read_buyer();
    write_buyer();
    
    return 0;
}