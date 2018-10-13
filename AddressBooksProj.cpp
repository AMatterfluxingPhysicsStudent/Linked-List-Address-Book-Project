#include <iostream>
using namespace std;

class singleContactEntry {
  public:
    string personLastName;
    string personFirstName;
    string phone_number;
    string address;
    string email;
};

class singleAddressBook {
  public:
    singleContactEntry contactsArray[100];
};

void listContactDetails(singleAddressBook &book1, int contactNumberForUse) {
  int u = contactNumberForUse;
  cout << "Last Name: " << book1.contactsArray[u].personLastName << endl;
  cout<< "First Name: " << book1.contactsArray[u].personFirstName<< endl;
  cout << "Email: " << book1.contactsArray[u].email << endl;
  cout << "Phone: " << book1.contactsArray[u].phone_number << endl;
  cout << "Address: " << book1.contactsArray[u].address << endl;
  cout << " " << endl;
  
}

void addAddress(singleAddressBook &book1, string lastName, string firstName, string phone_number, string address, string email, int &count) {
  singleContactEntry new_entry;

  new_entry.personLastName = lastName; 
  new_entry.personFirstName = firstName;
  new_entry.phone_number = phone_number;
  new_entry.address = address;
  new_entry.email = email;

  book1.contactsArray[count] = new_entry;
  count++;
  cout<<endl<<"There are now "<<count<<" contacts in this address book."<<endl<<endl;
}

void listAddedAddressAsToCheck(singleAddressBook &book1, int count) { //variant of listContactDetails() for addAddress() use only. Is for confirmation for user.
  int i = count - 1; 
  cout << "Last Name: " << book1.contactsArray[i].personLastName << endl;
  cout<< "First Name: " << book1.contactsArray[i].personFirstName<< endl;
  cout << "Email: " << book1.contactsArray[i].email << endl;
  cout << "Phone: " << book1.contactsArray[i].phone_number << endl;
  cout << "Address: " << book1.contactsArray[i].address << endl;
  cout << " " << endl;
  
}

void deleteAddress2(singleAddressBook &book1, int contactNumberForUse, int &count){
  //as shorthand
  int t = contactNumberForUse; 

  //Displaying what information you're deleting, to make sure.
  cout<<"Delete Contact Information of "<<book1.contactsArray[t].personLastName<<" with information:"<<endl;
  listContactDetails(book1, contactNumberForUse);

  //seeking confirmation
  string userResponse;
  cout<<"Confirm? Y/N"<<endl;
  cin>>userResponse;
  if (userResponse == "Yes"|| userResponse == "yes"|| userResponse == "y"||userResponse == "Y"){
    //nullifies for good measure, in case of overlapping variables
    book1.contactsArray[t].personLastName = "";
    book1.contactsArray[t].personFirstName = "";
    book1.contactsArray[t].phone_number = "";
    book1.contactsArray[t].email = "";
    book1.contactsArray[t].address = "";

    for(int iterations = 0; iterations < (count-contactNumberForUse); iterations++){ //shifts up all spots, starting from the deleted contact's spot;
      book1.contactsArray[t+iterations].personLastName = book1.contactsArray[t+iterations+1].personLastName;
      book1.contactsArray[t+iterations].personFirstName = book1.contactsArray[t+iterations+1].personFirstName;
      book1.contactsArray[t+iterations].phone_number = book1.contactsArray[t+iterations+1].phone_number;
      book1.contactsArray[t+iterations].email = book1.contactsArray[t+iterations+1].email;
      book1.contactsArray[t+iterations].address = book1.contactsArray[t+iterations+1].address;
    }
    count--;
  }
  else {
    return;
  }
}

//displaying initial menu
int displayMenu(int menuChoiceLocal) {
  cout << "1. Create new contact." << endl;
  cout << "2. Update existing contact." << endl;
  cout << "3. Delete a contact" << endl;
  cout << "4. List all existing contacts in sorted order." << endl;
  cout << "5. Search for a given contact" << endl;
  cout << "6. Quit address book." << endl;
  cout << "Choose course of action using designated numbers." << endl;
  cin >> menuChoiceLocal;
  
  return menuChoiceLocal;
}

void updateAddress(singleAddressBook &book1, int update_choice, string update_value, int contactNumberForUse, int &count){
  int i = contactNumberForUse; //having the name contactNumberForUse here is for ctrl F. ctrl F is like portal. i is easier to use below, however, as it is shorter.
  if (update_choice == 1) {
    book1.contactsArray[i].personLastName = update_value;
  } 
  else if (update_choice == 2) {
    book1.contactsArray[i].personFirstName = update_value;
  }
  else if (update_choice == 3){
    book1.contactsArray[i].email = update_value;
  } 
  else if (update_choice == 4) {
    book1.contactsArray[i].phone_number = update_value;
  } 
  else if (update_choice == 5) {
    book1.contactsArray[i].address = update_value;
  }
}

void listAllLastNamesTOC(singleAddressBook &book1, int &count){
  cout<<endl<<"Here are all the existing contacts:"<<endl;
  for(int p = 0; p < count; p++){
    cout<<"Contact #"<<p+1<<": "<<book1.contactsArray[p].personLastName<<endl;
  }
  cout<<endl;
}


void sortingContacts(singleAddressBook &book1,int count){
      //procedure
        //1. parse the first letters of each. e.g. char firstLetter = book1.contactsArray[0].personLastName[0];
        //2. grab first letters in array []
        //3. Ignore the problem of two different people with identical last names until later, because could take too much code. Method: increment n each loop where n = 1 means checking first position of string personName. If last names are identical, then check first names. Remember, iterate only at the very end of the first loop, first loop meaning when all first letters sit in sorted order.
        // 4. Selection sort the smaller array, but each time that you move around two array elements, ALSO shift around the information they represent
        //5.  
        //6. you could create a 3rd symbolic array, a number array, where alphabet letters are given either a = 1, b = 2, etc number values or given ASCII value
        // If two has the same first letters, then loop but iterate to another letter like w = 2 (well w = 1 actually but you know)
        //

      int letterPositionToParse = 0;
      int cycleIteration = 0;
      char parsedLetters1[count];
      for(cycleIteration = 0; cycleIteration < count; cycleIteration++) {
        char firstLetter = book1.contactsArray[cycleIteration].personLastName[letterPositionToParse];
        parsedLetters1[cycleIteration] = firstLetter;
      }//generating parsedLetters1[] array.

      int numberArray[count];
      string upperCaseAlphaBetArray = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      string lowerCaseAlphaBetArray = "abcdefghijklmnopqrstuvwxyz";

      for(cycleIteration = 0; cycleIteration < count; cycleIteration++) {
        for(int b = 1; b <= 26; b++) {
          if (parsedLetters1[cycleIteration] == upperCaseAlphaBetArray[b-1]||parsedLetters1[cycleIteration] == lowerCaseAlphaBetArray[b-1]){
            numberArray[cycleIteration] = b;
          }
        }
      }

      for(int i=0; i< count; i++){
        int minValue = i; //minValue holder is set to i, the starting point
        for (int j = i; j< count; j++) {// checks against all other values in array
          if(numberArray[j] < numberArray[minValue])
            minValue = j;//address is passed, no real moving is done
        }
        swap(numberArray[i],numberArray[minValue]);//swap;
        swap(parsedLetters1[i],parsedLetters1[minValue]);
        swap (book1.contactsArray[i].personLastName, book1.contactsArray[minValue].personLastName);
        swap (book1.contactsArray[i].personFirstName, book1.contactsArray[minValue].personFirstName);
        swap (book1.contactsArray[i].phone_number, book1.contactsArray[minValue].phone_number);
        swap (book1.contactsArray[i].address, book1.contactsArray[minValue].address);
        swap (book1.contactsArray[i].email, book1.contactsArray[minValue].email);
        
      }


}

//Search Function, will call on void listContactDetails(singleAddressBook &book1, int contactNumberForUse)
void searchGivenContact(singleAddressBook &book1, string contactSearchedFor, int arrayElementsOfFoundContacts[], int&count){
  int howManyMatches = 0;
  int q = 0;

  for (int w = 0; w<count; w++){
    if(contactSearchedFor == book1.contactsArray[w].personLastName){
      arrayElementsOfFoundContacts[q] = w;
      q++;
      howManyMatches++;
    }
  }
  if (howManyMatches >= 1){
    cout<<"Found contacts:"<<endl;
    for(int g = 0; g < howManyMatches; g++){
      cout<<arrayElementsOfFoundContacts[g]+1<<". "<<book1.contactsArray[arrayElementsOfFoundContacts[g]].personLastName<<", "<<book1.contactsArray[arrayElementsOfFoundContacts[g]].personFirstName<<endl;
    }

    int viewFurther;
    cout<<"Enter the allocated number address of the desired contact to view further details."<<endl;
    cin>>viewFurther;
    int contactNumberForUse = viewFurther - 1;
    listContactDetails(book1, contactNumberForUse);

  }
  if (howManyMatches <1){
    cout << "We couldn't find a user with that information. Please try again." << endl<<endl;
  }
}


int main() {
  //declaring variables. This indent is for the indent tiers feature, the + and - on the left side of repl.
    string lastName;

    string firstName;
    string phone_number; 
    string email; 
    string address; 
    
    //instantiate a singleAddressBook instance    
    singleAddressBook book1; //can turn into book[], if want to take advantage of having separate address books

    int update_choice;
    string update_value;
    int count = 0;
    
    cout<<"Your Address Book."<<endl;
  //warnings, temporary to MVP
    cout<<"Warning: Minimum Viable Product can NOT handle spaces in user input."<<endl;

  int loopConstraints = 2;
  while (loopConstraints <8){  //Using bool = true/false was buggy. Try yourself and see. 2 and 8 are chosen arbitarily.
    int menuChoiceLocal;  
    menuChoiceLocal = displayMenu(menuChoiceLocal);

    if(menuChoiceLocal == 1) {
      cout << "Enter the new contact's last name:" <<endl; 
      cin >> lastName;//or could use an array
      cout<<"Enter the new contact's first name:"<<endl;
      cin>> firstName;
      cout << "Enter contact phone number" << endl;
      cin >> phone_number;
      cout << "Enter contact email:" << endl;
      cin >> email;
      cout << "Enter contact address:" << endl;
      cin >> address;

      addAddress(book1, lastName, firstName, phone_number, address, email, count);
      listAddedAddressAsToCheck(book1, count);
      sortingContacts(book1, count);
    } 
    else if (menuChoiceLocal == 2) {
      //1. list all available contact names, which means that listing in sorted order should be done before this here is done
      //2. list all the information about that name after it has been selected, such as listAddedAddressAsToCheck()
      //I think we should find it here, list it, and then update it.
      int contactNumber;
      int contactNumberForUse;
      listAllLastNamesTOC(book1, count);
      
      cout << "Select Contact by Entering Contact Number:" << endl;
      cin >> contactNumber;
      cout<<endl<<"The selected contact is number "<<contactNumber<<"."<<endl;
      contactNumberForUse = contactNumber - 1;

      //diplay details of that name here***
      listContactDetails(book1, contactNumberForUse);


      cout << "Enter what you would like to update."<<endl;
      cout<< "1. Last Name" <<endl;
      cout<< "2. First Name" <<endl;
      cout<< "3. Phone Number" <<endl;
      cout<<"4. Email"<<endl;
      cout<<"5. Address." <<endl;
      cout<<"Select What to Update by Numbers 1-5."<<endl;
      cin >> update_choice;
      cout << "Enter new information." << endl;
      cin >> update_value;

      updateAddress(book1, update_choice, update_value, contactNumberForUse, count);

      sortingContacts(book1, count);
    } 
    else if (menuChoiceLocal == 3) {
      // cout << "Enter contact last name" << endl;
      // cin >> lastName;
      int contactNumber;
      int contactNumberForUse;
      listAllLastNamesTOC(book1, count);
      cout << "Select Contact by Entering Contact Number:" << endl;
      cin >> contactNumber;
      cout<<endl<<"The selected contact for deletion is number "<<contactNumber<<"."<<endl;
      contactNumberForUse = contactNumber - 1;


      deleteAddress2(book1, contactNumberForUse, count);
      sortingContacts(book1, count);
    } 
    else if (menuChoiceLocal == 4){
      sortingContacts(book1, count);
      listAllLastNamesTOC (book1, count);
    }
    else if (menuChoiceLocal == 5){
      listAllLastNamesTOC (book1, count);

      string contactSearchedFor;
      cout<<"Search for a contact by entering their last name:"<<endl;
      cin>>contactSearchedFor;

      int arrayElementsOfFoundContacts[count];

      searchGivenContact(book1, contactSearchedFor, arrayElementsOfFoundContacts, count);
      sortingContacts(book1, count);
    }
    else if (menuChoiceLocal == 6){
      loopConstraints = 10; 
    }
    // else if (menuChoiceLocal == 6){
      // loopContinues = false; //WHY DOES THE LOOP TREAT THIS AS IF IT'S NOT IN AN IF STATEMENT
    // }

    //ENDING:
    cout<<"Returning to Main Menu."<<endl;
    int linesBetweenEntries = 3;
    for(int d = 1; d <= linesBetweenEntries; d++){
      cout<<endl;
    }
  }
}
