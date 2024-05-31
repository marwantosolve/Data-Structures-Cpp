#include "Infix-To-Postfix.cpp"

bool isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return true;
  else
    return false;
}

int performOperation(int op1, int op2, char op) {
  int ans;
  switch (op) {
    case '+':
      ans = op2 + op1;
      break;
    case '-':
      ans = op2 - op1;
      break;
    case '*':
      ans = op2 * op1;
      break;
    case '/':
      ans = op2 / op1;
      break;
  }
  return ans;
}

void evaluatePostfix(string exp) {
  char buffer[15];
  int i, op1, op2, len, j, x;
  stack<int> s;
  len = exp.length();
  j = 0;
  for (i = 0; i < len; i++) {
    if (exp[i] >= '0' && exp[i] <= '9') {
      buffer[j++] = exp[i];
    } else if (exp[i] == ' ') {
      if (j > 0) {
        buffer[j] = '\0';
        x = atoi(buffer);
        s.push(x);
        j = 0;
      }
    } else if (isOperator(exp[i])) {
      op1 = s.top();
      s.pop();
      op2 = s.top();
      s.pop();
      s.push(performOperation(op1, op2, exp[i]));
    } else {
      cout << "Invalid Expression !";
      exit(0);
    }
  }
  cout << "The Answer = " << s.top();
}

int main() {
  string choice;
  cout << "Choose Expression Type:\n(1) Infix\n(2) Postfix\n"
          ">> ";
  getline(cin, choice);
  if (choice == "1") {
    string exp1;
    cout << "Enter a Infix Expression (like: ( 2 + 3 ) * 4 ):\n"
            ">> ";
    getline(cin, exp1);
    string postfixExp;
    postfixExp = InfixToPostfix(exp1);
    cout << "Postfix Expression: [ " << postfixExp << " ]\n";
    string exp2;
    cout << "Enter the same Postfix Expression (with spaces between numbers):\n"
            ">> ";
    getline(cin, exp2);
    evaluatePostfix(exp2);
  } else if (choice == "2") {
    string exp2;
    cout << "Enter a Postfix Expression(like: 4 5 * ):\n"
            ">> ";
    getline(cin, exp2);
    evaluatePostfix(exp2);
  } else {
    cout << "Invalid Choice !";
    return 0;
  }
}
