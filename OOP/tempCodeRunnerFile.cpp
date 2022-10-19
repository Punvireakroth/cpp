int main(){
    // d) Declare an object
    House hObj;

    string address;
    float price;

    // e ) Prompt user to enter the type and address 
    cout<<"Enter Type"<<endl;
    cin >> hObj.strType;

    cout<<"Enter Address"<<endl;
    cin >> address;
    hObj.setAddress(address);

    cout<<"Enter Price"<<endl;
    cin>>price;
    hObj.setPrice(price);

    // f) Display type and address of the object

    cout << "Type = "<< hObj.strType << ":: Address = " << hObj.getAddress() << ":: Price = " <<  hObj.getPrice() <<endl;
}