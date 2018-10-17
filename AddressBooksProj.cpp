#include <iostream>
#include <string>
using namespace std;

struct node {
  string personLastName;
  string personFirstName;
  string phoneNumber;
  string address;
  string email;
  struct node* next;
  struct node* last;
};
struct node* declareNewNode1 (struct node* head, int &count){
  string personLastName;
  string personFirstName;
  string phoneNumber;
  string address;
  string email;
  //node creation
    struct node* newNode = new node;
    //data requesting
      cout<<"Enter the new contact's Last Name:"<<endl;
      getline(cin, personLastName);
      newNode->personLastName = personLastName;
      cout<<"Enter the new contact's First Name:"<<endl;
      getline(cin, personFirstName);
      newNode->personFirstName = personFirstName;
      cout<<"Enter the new contact's PhoneNumber:"<<endl;
      getline(cin, phoneNumber);
      newNode->phoneNumber = phoneNumber;
      cout<<"Enter the new contact's Email:"<<endl;
      getline(cin, email);
      newNode->email = email;
      cout<<"Enter the new contact's Address:"<<endl;
      getline(cin, address);
      newNode->address = address;
      count++;  
  //address setting
    if (count == 1){
      head = newNode;
      head->next = NULL;
    }
    else{
      //find the last node and link it
        struct node* currentNode = head;
        while(currentNode->next != NULL){
          currentNode = currentNode->next;
        }
      //linking
        currentNode->next = newNode;
        newNode->last = currentNode;
    }
 
  return head;//wait you don't need to return a head; actually you do or this wouldn't find the head again
  //What was the big problem? Problem was I kept overreaching my memory. I couldn't hold all the data, I think. Thus, my memory kept failing and I went nowhere. Solution: chunk so that I didn't need so much overhead switching and handled all the data in two big chunks.
}
void displayAllLastNames (struct node* head, int count){
  struct node* currentNode = head;
  for (int o = 1; currentNode != NULL;o++) {
      cout<<" Contact #"<<o<<":   "<<currentNode->personLastName<<endl;
      currentNode = currentNode->next;
    }
  cout<<count<<" contacts exist."<<endl;
}
string displayMainMenu2(){
  string string1;
  string firstLet;
  cout<<"Press C to Create a New Contact, V to View a Contact, Q to Quit otherwise."<<endl;
  getline(cin,string1);
  firstLet = string1[0];
  return firstLet;
}
void displayNode (struct node* address){ 
  cout<<"Last Name: "<<address->personLastName<<endl;
  cout<<"First Name: "<<address->personFirstName<<endl;
  cout<<"Phone Number: "<<address->phoneNumber<<endl;
  cout<<"Email: "<<address->email<<endl;
  cout<<"Address: "<<address->address<<endl;
}
//finding functions using conditions
  struct node* findAddressConditionIsNodeNum (struct node* head, int count, string nthString){
    int nthInt = stoi(nthString);
    //going to the proper node and retrieving the address
      struct node* currentNode = head;
      int pos = 1;
      while(pos != nthInt||pos > 2*count){
        currentNode = currentNode->next;
        pos++;
      }
      if (pos > 100){
        cout<<"Please enter the position again."<<endl;
        findAddressConditionIsNodeNum(head, count, nthString);
      }
    //return the address
      return currentNode;  
  }

  struct node* findAddressConditionIsLastName (struct node* head, string lookFor){
    //going to the proper node and retrieving the address
      struct node* currentNode = head;
      while(currentNode->personLastName != lookFor){
        currentNode = currentNode->next;
      }
    //returning the address
      return currentNode;
  }

  struct node* findAddressConditionIsFirstName (struct node* head, string lookFor){
    //going to the proper node and retrieving the address
      struct node* currentNode = head;
      while(currentNode->personFirstName != lookFor){
        currentNode = currentNode->next;
      }
    //returning the address
      return currentNode;
  }
  
  struct node* findAddressConditionIsPhoneNumber (struct node* head, string lookFor){
    //going to the proper node and retrieving the address
      struct node* currentNode = head;
      while(currentNode->phoneNumber != lookFor){
        currentNode = currentNode->next;
      }
    //returning the address
      return currentNode;
  }

  struct node* findAddressConditionIsEmail (struct node* head, string lookFor){
    //going to the proper node and retrieving the address
      struct node* currentNode = head;
      while(currentNode->email != lookFor){
        currentNode = currentNode->next;
      }
    //returning the address
      return currentNode;
  }

    struct node* findAddressConditionIsAddress (struct node* head, string lookFor){
    //going to the proper node and retrieving the address
      struct node* currentNode = head;
      while(currentNode->address != lookFor){
        currentNode = currentNode->next;
      }
    //returning the address
      return currentNode;
  }


void editContactEntry(struct node* address){
  int loopC = 2;
  while(loopC < 7){
    string editChoice;
    string e;  
    cout<<"Press L to Edit "<<address->personLastName<<endl;
    cout<<"Press F to Edit "<<address->personFirstName<<endl;
    cout<<"Press E to Edit "<<address->email<<endl;
    cout<<"Press P to Edit "<<address->phoneNumber<<endl;
    cout<<"Press A to Edit "<<address->address<<endl;
    cout<<"Press Q to Return to Previous Menu."<<endl;
    getline(cin, editChoice);
    e = editChoice[0];

    if (e == "L"||e == "l"){
      string newLastName;
      cout<<"Enter new last name: ";
      getline(cin, newLastName);
      address->personLastName = newLastName;
    }
    else if (e == "F"||e == "f"){
      string newFirstName;
      cout<<"Enter new First Name: ";
      getline(cin, newFirstName);
      address->personFirstName = newFirstName;
    }
    else if (e == "E"||e == "e"){
      string newEmail;
      cout<<"Enter new Email: ";
      getline(cin, newEmail);
      address->email = newEmail;
    }
    else if (e == "P"||e == "p"){
      string newPhoneNum;
      cout<<"Enter new Phone Number: ";
      getline(cin, newPhoneNum);
      address->phoneNumber = newPhoneNum;
    }
    else if (e == "A"||e == "a"){
      string newAddress;
      cout<<"Enter new Address: ";
      getline(cin, newAddress);
      address->address = newAddress;
    }
    else if (e == "Q"||e == "q"){
      loopC = 10;
    }

    cout<<endl;
  }
}

void deletingContactEntry(struct node* address, int &count){
  //link last and next nodes
  struct node* nextNode = address->next;
  struct node* lastNode = address->last;
  lastNode->next = nextNode;
  nextNode->last = lastNode;

  address->personLastName = "";
  address->personFirstName = "";
  address->phoneNumber = "";
  address->address = "";
  address->email = "";
  delete address;
  count--;
  //oof list item deleting is so much easier in linked lists
}

void viewSpecificContact(struct node* head, int &count){
  string holder;
  string searchMethodSelection;
  struct node* address = NULL;
  cout<<"Press N to Select Contact by its Position in the Entries."<<endl;
  cout<<"Press L to Search For Contact by Last Name."<<endl;
  cout<<"Press F to Search For Contact by First Name."<<endl;
  cout<<"Press E to Search For Contact By Email."<<endl;
  cout<<"Press P to Search For Contact By Phone Number."<<endl;
  cout<<"Press A to Search For Contact By Address."<<endl;
  cout<<"Press Q to Return to Previous Menu."<<endl;
  getline(cin, holder);
  searchMethodSelection = holder[0];
  
  if(searchMethodSelection == "N"||searchMethodSelection == "n"){
    string nth;
    cout<<"Enter entry #:";
    getline(cin, nth);
    address = findAddressConditionIsNodeNum (head, count, nth);
  }
  else if(searchMethodSelection == "L"||searchMethodSelection == "l"){
    string lookFor;
    cout<<"Enter Last Name to Search By: ";
    getline(cin, lookFor);
    address = findAddressConditionIsLastName (head, lookFor);
  }
  else if(searchMethodSelection == "F"||searchMethodSelection == "f"){
    string lookFor;
    cout<<"Enter First Name to Search By: ";
    getline(cin, lookFor);
    address = findAddressConditionIsFirstName (head, lookFor);
  }
  else if(searchMethodSelection == "E"||searchMethodSelection == "e"){
    string lookFor;
    cout<<"Enter Email to Search By: ";
    getline(cin, lookFor);
    address = findAddressConditionIsEmail (head, lookFor);
  }
  else if(searchMethodSelection == "P"||searchMethodSelection == "p"){
    string lookFor;
    cout<<"Enter Phone Number to Search By: ";
    getline(cin, lookFor);
    address = findAddressConditionIsPhoneNumber (head, lookFor);
  }
  else if(searchMethodSelection == "A"||searchMethodSelection == "a"){
    string lookFor;
    cout<<"Enter Address to Search By: ";
    getline(cin, lookFor);
    address = findAddressConditionIsAddress (head, lookFor);
  }
  else if(searchMethodSelection == "Q"||searchMethodSelection == "q"){
    return;
  }
  displayNode(address);
  string choice;
  string ch;

  cout<<"Press E to edit the Contact."<<endl;
  cout<<"Press D to delete the Contact."<<endl;
  cout<<"Press R to return to main menu."<<endl;
  getline(cin, choice);
  ch = choice[0];

  if(ch == "E"||ch == "e"){
    editContactEntry(address);
  }
  if(ch == "D"||ch == "d"){
    deletingContactEntry(address, count);
  }
  if(ch == "R"||ch == "r"){
    
  }
}

struct node* callingChosenFunction(string menuChoice, struct node* head, int &count, int &loopContinue){
  if (menuChoice == "C"||menuChoice == "c"){
    head = declareNewNode1(head, count);
  }
  else if (menuChoice == "V"||menuChoice == "v"){
    viewSpecificContact(head, count);
  }
  else if (menuChoice == "Q"||menuChoice == "q"){
    loopContinue = 10;
  }
  return head;
}

int main() {
  //declare head and count
    struct node* head = NULL;
    int count = 0;

  string menuChoice;
  int loopContinue = 2;
  cout<<"Welcome to your address book!"<<endl;
  while(loopContinue < 8){
    cout<<"This is the main menu. ";
    cout<<"Here are all your contacts:"<<endl;
    displayAllLastNames(head, count);
      cout<<endl;
    menuChoice = displayMainMenu2();
    head = callingChosenFunction(menuChoice, head, count, loopContinue);
    cout<<endl;
  }

  struct node* currentNode = head;
  struct node* nodeToDelete = NULL;
  
  for(int r = 1; r <= count; r++){
    nodeToDelete = currentNode;
    currentNode = currentNode->next;
    nodeToDelete->personLastName = "";
    nodeToDelete->personFirstName = "";
    nodeToDelete->email = "";
    nodeToDelete->address = "";
    nodeToDelete->phoneNumber = "";
    delete nodeToDelete;
  }
}

