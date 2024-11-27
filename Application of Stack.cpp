#include <iostream>

#include <stack>

#include <cctype> // For isdigit |||||||||||||||||||||

#include <cmath>  // For pow 

using namespace std;



// Function to perform arithmetic operations |||||||||||||||||

int applyOperation(int a, int b, char op) {

    switch (op) {

        case '+': return a + b;

        case '-': return a - b;

        case '*': return a * b;

        case '/': return a / b;

        // case '^'  return pow a, b 

        default: return 0;

    }

}



// Function to check precedence of operators |||||||||||||||||||||||||||

int precedence(char op) {

    if (op == '+' || op == '-') return 1;

    if (op == '*' || op == '/') return 2;

    // if (op == '^') return 3

    return 0;

}



// Function to evaluate the top operation on stacks |||||||||||||||||||||||||||||||||

void processTopOperation(stack<int>& values, stack<char>& ops) {

    int val2 = values.top();

    values.pop();



    int val1 = values.top();

    values.pop();



    char op = ops.top();

    ops.pop();



    values.push(applyOperation(val1, val2, op));

}



// Function to evaluate infix expressions ||||||||||||||||||||||||||||||||||||||

int evaluateInfix(string infix) {

    stack<int> values; // Stack to store operands |||||||||||||

    stack<char> ops;   // Stack to store operators and parentheses |||||||||||||



    for (int i = 0; i < infix.length(); i++) {

        char c = infix[i];



        // If the current character is a whitespace skip it |||||||||||||||||||

        if (isspace(c))

            continue;



        // If the current character is a digit parse the whole number and push it onto the stack ||||||||||||||||

         if (isdigit(c)) {

            int value = 0;

            // There may be multiple digits in the number ||||||||||||||||||||

            while (i < infix.length() && isdigit(infix[i])) {

                value = value * 10 + (infix[i] - '0');

                i++;

            }

            values.push(value);

            i--; // Since the outer loop will increment we decrement it here |||||||||||||||||||

        }

        // If the current character is '(' push it onto the ops stack ||||||||||||||||||||||||||

        else if (c == '(') {

            ops.push(c);

        }

        // If the current character is ')' solve the entire expression within the parentheses ||||||||||

        else if (c == ')') {

            while (!ops.empty() && ops.top() != '(') {

                processTopOperation(values, ops);

            }

            ops.pop(); // Pop the '(' |||||||||||||

        }

        // If the current character is an operator |||||||||

        else {

            // While the top of the operator stack has the same or higher precedence apply the operator ||||||||||

            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {

                processTopOperation(values, ops);

            }

            // Push the current operator onto the operator stack ||||||||||||

            ops.push(c);

        }

    }



    // After traversing the entire expression, apply the remaining operations ||||||||||||||||||||||||||||||||||||||

    while (!ops.empty()) {

        processTopOperation(values, ops);

    }



    // The final result is the top of the values stack |||||||||||||||||||||||||||||||||||||||||||||||

    return values.top();

}



int main() {

    string infix;

    cout << "\n" "Enter an infix expression e.g., 3 + 5 - 2 * 3/2: ";

    getline(cin, infix);



    int result = evaluateInfix(infix);

    cout << "Result: " << result << endl;



    return 0;

}