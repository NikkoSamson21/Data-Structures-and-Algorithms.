class Stack {

    private:

        int top;

        int maxSize;

        int* stackArray;



    public:

        Stack(int size) {

            maxSize = size;

            stackArray = new int(maxSize);

            top = -1;

        }



        ~Stack() {

            delete[] stackArray;

        }




int main() {

    Stack stack(6);



        bool isEmpty() { 

        cout << "Is Empty?: " << stackArray.isEmpty() << endl;

        }





        bool isFull() {

        cout << "Is full?: " << stack.isFull() << endl;



        }

        void push(int value) {

            stack.push(10);

            stack.push(20);

            stack.push(30);

            stack.push(40);

            stack.push(50);

            stack.push(60);



        }

        void pop() {

            stack.pop();

            stack.pop();



        }

        int peek() {

            stack.peek();

        }

    }   

};