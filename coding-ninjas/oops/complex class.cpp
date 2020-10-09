/**********

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
 
 ************/
 
class ComplexNumbers {
    // Complete this class
    private:
    int real;
    int imaginary;
    public:
    ComplexNumbers(int real,int imaginary){
        this->real=real;
        this->imaginary=imaginary;
    }
    
    void print(){
        cout<<this->real<<" "<<"+"<<" "<<"i"<<this->imaginary<<endl;
    }
    
    void plus(ComplexNumbers const &a){
        this->real+=a.real;
        this->imaginary+=a.imaginary;
    }
    
    void multiply(ComplexNumbers const &a){
        int real1=this->real,imag1=this->imaginary;
        this->real=(this->real)*a.real -(this->imaginary)*a.imaginary;
        this->imaginary=real1*a.imaginary + (imag1)*a.real;
    }
    
};
