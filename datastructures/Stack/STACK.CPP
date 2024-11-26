#include <iostream.h>
#include <conio.h>


class Stack{

    private:

    int tos;
    int *stack;
    int size;

    static int counter;

    public:

    Stack(int n =10){
        tos = 0;
        size = n;
        stack = new int[size];
        counter++;
        cout<<"this is constructor of stack obj with size "<<n<<endl;
    }


    ~Stack(){
        delete[] stack;
        cout<<"this is destructor"<<endl;
	}

	static int getCounter(){
		return counter;
	}

	void push(int element);
	int pop();

	friend void viewContent(Stack s);

};

void viewContent(Stack s){
    int t = s.tos;

    while (t != 0)
    {
		cout << s.stack[--t] << endl;
    }
    
}

void Stack::push(int element){
	if(tos != size){
		stack[tos++] = element;
	}else{
		cout<<"Stack is Full"<<endl;
	}
}

int Stack::pop(){

    if(tos != 0){
        tos--;
        return stack[tos];
    }else{
        cout<<"Stack is empty"<<endl;
    }

    return -1;
}

void swap(int* a, int* b)
{
    int temp = *a;
	*a = *b;
    *b = temp;
}

int Stack::counter = 0;


int main(){
	int i;

	clrscr();
	cout<<"number of objects: "<<Stack::getCounter()<<endl;

	Stack s(3);

    s.push(5);
	//s.push(6);
   // s.push(7);
	//s.push(7);

	cout<<"number of objects: "<<Stack::getCounter()<<endl;

    viewContent(s);

	s.push(5);
	s.push(8);

	viewContent(s);

	cin>>i;

	return 0;
}