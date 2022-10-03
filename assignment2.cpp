#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cstring>
using namespace std;

//Function to ask the user to enter a prompt
void ask(){
    cout << endl;
    cout << "What would you like to do?" << endl << flush;
    cout << "1: Look up year range" << endl << flush;
    cout << "2: Search for author" << endl << flush;
    cout << "3: Search for title" << endl << flush;
    cout << "Q: Quit" << endl << flush;
    cout << "> ";
}

// Function searching for year range
void optionOne(string eYear, string bYear){
    /* Data is in one line for easier code reading */
    string data[][5]={{"A Breath of Snow and Ashes","Diana Gabaldon","Delacorte","10/16/2005","Fiction"},{"A Common Life","Jan Karon","Viking","4/29/2001","Fiction"},{"A Dance With Dragons","George R. R. Martin","Bantam","7/31/2011","Non Fiction"},{"A Day Late and a Dollar Short","Terry McMillan","Viking","2/4/2001","Fiction"},{"A Feast For Crows","George R. R. Martin","Bantam","11/27/2005","Fiction"},{"A Lion Is In the Streets","Adria Locke Langley","McGraw","7/1/1945","Non Fiction"},{"A Man In Full","Tom Wolfe","Farrar","11/22/1998","Fiction"},{"A Painted House","John Grisham","Doubleday","2/25/2001","Non Fiction"},{"A Perfect Spy","John le Carre","Knopf","5/4/1986","Fiction"},{"A Rage to Live","John O'Hara","Random House","9/18/1949","Fiction"},{"A Shade of Difference","Allen Drury","Doubleday","10/28/1962","Non Fiction"},{"A Thousand Splendid Suns","Khaled Hosseini","Riverhead","6/10/2007","Fiction"},{"A Tree Grows In Brooklyn","Betty Smith","Harper","1/2/1944","Fiction"},{"A Widow For One Year","John Irving","Random House","6/14/1998","Non Fiction"},{"Accident","Danielle Steel","Delacorte","2/27/1994","Fiction"},{"Acheron","Sherrilyn Kenyon","St. Martin's","8/24/2008","Non Fiction"},{"Across the River and Into the Trees","Ernest Hemingway","Scribner's","10/15/1950","Fiction"},{"Advise and Consent","Allen Drury","Doubleday","10/4/1959","Non Fiction"},{"Against All Enemies","Tom Clancy","Putnam","7/3/2011","Non Fiction"},{"Airframe","Michael Crichton","Knopf","12/29/1996","Fiction"},{"Airport","Arthur Hailey","Doubleday","4/7/1968","Non Fiction"},{"Alaska","James Michener","Random House","7/3/1988","Fiction"},{"Alex Cross's Trial","James Patterson","Brown","9/13/2009","Non Fiction"},{"American Assassin","Vince Flynn","Atria","10/31/2010","Fiction"},{"An Indecent Obsession","Colleen McCullough","Harper","11/15/1981","Fiction"},{"Anansi Boys","Neil Gaiman","Morrow","10/9/2005","Fiction"},{"Anathem","Neal Stephenson","William Morrow","9/28/2008","Fiction"},{"Anatomy of a Murder","Robert Traver","St. Martin's","3/9/1958","Non Fiction"},{"And Now Tomorrow","Rachel Field","MacMillan","8/9/1942","Non Fiction"},{"Andersonville","McKinley Kantor","World Publishing","1/1/1956","Fiction"},{"Angels Fall","Nora Roberts","Putnam","7/30/2006","Fiction"},{"Answered Prayers","Danielle Steel","Delacorte","11/17/2002","Fiction"},{"Arch of Triumph","Erich Maria Remarque","Appleton-Century","3/10/1946","Fiction"},{"Armageddon","Tim LaHaye","Tyndale","4/27/2003","Fiction"},{"At First Sight","Nicholas Sparks","Warner","11/6/2005","Non Fiction"},{"Bad Moon Rising","Sherrilyn Kenyon","St. Martin's","8/23/2009","Non Fiction"},{"Bag of Bones","Stephen King","Scribner","10/11/1998","Non Fiction"},{"Beach Music","Pat Conroy","Talese/Doubleday","7/16/1995","Fiction"},{"Before I Say Goodbye","Mary Higgins Clark","Simon & Schuster","5/7/2000","Fiction"},{"Best Friends Forever","Jennifer Weiner","Atria","8/2/2009","Fiction"}};

    // "stoi" = concatenating string to an int, activated by #include<sstream>
    int beginningYear = stoi(bYear);
    int endYear = stoi(eYear);

    // Looping through the range of years input
    for(int i = 0; i <= endYear - beginningYear; i++){
        // Concatenating year to string to be able to compare to array values
        string theYear = to_string(beginningYear + i);

        // Running through the whole array
        for(int j = 0; j <= 39; j++){
            // if the occurence of strYear.cstr() (The input passed multiple times in this case)
            // is a date in the array of each line
            if(strstr(data[j][3].c_str(), theYear.c_str())){
                // then print the contents of the data
                cout << data[j][0] << ", " << data[j][1] << ", " << data[j][2] << ", " << data[j][3] << ", " << data[j][4] << endl;
            }
        }
    }
}

// Function searching for author
void optionTwo(string author){
    /* Data is in one line for easier code reading */
    string data[][5]={{"A Breath of Snow and Ashes","Diana Gabaldon","Delacorte","10/16/2005","Fiction"},{"A Common Life","Jan Karon","Viking","4/29/2001","Fiction"},{"A Dance With Dragons","George R. R. Martin","Bantam","7/31/2011","Non Fiction"},{"A Day Late and a Dollar Short","Terry McMillan","Viking","2/4/2001","Fiction"},{"A Feast For Crows","George R. R. Martin","Bantam","11/27/2005","Fiction"},{"A Lion Is In the Streets","Adria Locke Langley","McGraw","7/1/1945","Non Fiction"},{"A Man In Full","Tom Wolfe","Farrar","11/22/1998","Fiction"},{"A Painted House","John Grisham","Doubleday","2/25/2001","Non Fiction"},{"A Perfect Spy","John le Carre","Knopf","5/4/1986","Fiction"},{"A Rage to Live","John O'Hara","Random House","9/18/1949","Fiction"},{"A Shade of Difference","Allen Drury","Doubleday","10/28/1962","Non Fiction"},{"A Thousand Splendid Suns","Khaled Hosseini","Riverhead","6/10/2007","Fiction"},{"A Tree Grows In Brooklyn","Betty Smith","Harper","1/2/1944","Fiction"},{"A Widow For One Year","John Irving","Random House","6/14/1998","Non Fiction"},{"Accident","Danielle Steel","Delacorte","2/27/1994","Fiction"},{"Acheron","Sherrilyn Kenyon","St. Martin's","8/24/2008","Non Fiction"},{"Across the River and Into the Trees","Ernest Hemingway","Scribner's","10/15/1950","Fiction"},{"Advise and Consent","Allen Drury","Doubleday","10/4/1959","Non Fiction"},{"Against All Enemies","Tom Clancy","Putnam","7/3/2011","Non Fiction"},{"Airframe","Michael Crichton","Knopf","12/29/1996","Fiction"},{"Airport","Arthur Hailey","Doubleday","4/7/1968","Non Fiction"},{"Alaska","James Michener","Random House","7/3/1988","Fiction"},{"Alex Cross's Trial","James Patterson","Brown","9/13/2009","Non Fiction"},{"American Assassin","Vince Flynn","Atria","10/31/2010","Fiction"},{"An Indecent Obsession","Colleen McCullough","Harper","11/15/1981","Fiction"},{"Anansi Boys","Neil Gaiman","Morrow","10/9/2005","Fiction"},{"Anathem","Neal Stephenson","William Morrow","9/28/2008","Fiction"},{"Anatomy of a Murder","Robert Traver","St. Martin's","3/9/1958","Non Fiction"},{"And Now Tomorrow","Rachel Field","MacMillan","8/9/1942","Non Fiction"},{"Andersonville","McKinley Kantor","World Publishing","1/1/1956","Fiction"},{"Angels Fall","Nora Roberts","Putnam","7/30/2006","Fiction"},{"Answered Prayers","Danielle Steel","Delacorte","11/17/2002","Fiction"},{"Arch of Triumph","Erich Maria Remarque","Appleton-Century","3/10/1946","Fiction"},{"Armageddon","Tim LaHaye","Tyndale","4/27/2003","Fiction"},{"At First Sight","Nicholas Sparks","Warner","11/6/2005","Non Fiction"},{"Bad Moon Rising","Sherrilyn Kenyon","St. Martin's","8/23/2009","Non Fiction"},{"Bag of Bones","Stephen King","Scribner","10/11/1998","Non Fiction"},{"Beach Music","Pat Conroy","Talese/Doubleday","7/16/1995","Fiction"},{"Before I Say Goodbye","Mary Higgins Clark","Simon & Schuster","5/7/2000","Fiction"},{"Best Friends Forever","Jennifer Weiner","Atria","8/2/2009","Fiction"}};
    // Make the first index of the input name an uppercase letter by default
    author[0] = toupper(author[0]);
    for(int i = 0; i <= 39; i++){
      if(strstr(data[i][1].c_str(), author.c_str())){
        if(strstr(data[i][1].c_str(), " ")){
          int index = author.find(" ");
          toupper(index+1);
          cout << data[i][0] << ", " << data[i][1] << ", " << data[i][2] << ", " << data[i][3] << ", " << data[i][4] << endl;
        }else{
          if(strcmp(data[i][1].c_str(), author.c_str())){
            cout << data[i][0] << ", " << data[i][1] << ", " << data[i][2] << ", " << data[i][3] << ", " << data[i][4] << endl;
          }
        } 
      }    
    }
}

// Function using book title
void optionThree(string title){
    /* Data is in one line for easier code reading */
    string data[][5]={{"A Breath of Snow and Ashes","Diana Gabaldon","Delacorte","10/16/2005","Fiction"},{"A Common Life","Jan Karon","Viking","4/29/2001","Fiction"},{"A Dance With Dragons","George R. R. Martin","Bantam","7/31/2011","Non Fiction"},{"A Day Late and a Dollar Short","Terry McMillan","Viking","2/4/2001","Fiction"},{"A Feast For Crows","George R. R. Martin","Bantam","11/27/2005","Fiction"},{"A Lion Is In the Streets","Adria Locke Langley","McGraw","7/1/1945","Non Fiction"},{"A Man In Full","Tom Wolfe","Farrar","11/22/1998","Fiction"},{"A Painted House","John Grisham","Doubleday","2/25/2001","Non Fiction"},{"A Perfect Spy","John le Carre","Knopf","5/4/1986","Fiction"},{"A Rage to Live","John O'Hara","Random House","9/18/1949","Fiction"},{"A Shade of Difference","Allen Drury","Doubleday","10/28/1962","Non Fiction"},{"A Thousand Splendid Suns","Khaled Hosseini","Riverhead","6/10/2007","Fiction"},{"A Tree Grows In Brooklyn","Betty Smith","Harper","1/2/1944","Fiction"},{"A Widow For One Year","John Irving","Random House","6/14/1998","Non Fiction"},{"Accident","Danielle Steel","Delacorte","2/27/1994","Fiction"},{"Acheron","Sherrilyn Kenyon","St. Martin's","8/24/2008","Non Fiction"},{"Across the River and Into the Trees","Ernest Hemingway","Scribner's","10/15/1950","Fiction"},{"Advise and Consent","Allen Drury","Doubleday","10/4/1959","Non Fiction"},{"Against All Enemies","Tom Clancy","Putnam","7/3/2011","Non Fiction"},{"Airframe","Michael Crichton","Knopf","12/29/1996","Fiction"},{"Airport","Arthur Hailey","Doubleday","4/7/1968","Non Fiction"},{"Alaska","James Michener","Random House","7/3/1988","Fiction"},{"Alex Cross's Trial","James Patterson","Brown","9/13/2009","Non Fiction"},{"American Assassin","Vince Flynn","Atria","10/31/2010","Fiction"},{"An Indecent Obsession","Colleen McCullough","Harper","11/15/1981","Fiction"},{"Anansi Boys","Neil Gaiman","Morrow","10/9/2005","Fiction"},{"Anathem","Neal Stephenson","William Morrow","9/28/2008","Fiction"},{"Anatomy of a Murder","Robert Traver","St. Martin's","3/9/1958","Non Fiction"},{"And Now Tomorrow","Rachel Field","MacMillan","8/9/1942","Non Fiction"},{"Andersonville","McKinley Kantor","World Publishing","1/1/1956","Fiction"},{"Angels Fall","Nora Roberts","Putnam","7/30/2006","Fiction"},{"Answered Prayers","Danielle Steel","Delacorte","11/17/2002","Fiction"},{"Arch of Triumph","Erich Maria Remarque","Appleton-Century","3/10/1946","Fiction"},{"Armageddon","Tim LaHaye","Tyndale","4/27/2003","Fiction"},{"At First Sight","Nicholas Sparks","Warner","11/6/2005","Non Fiction"},{"Bad Moon Rising","Sherrilyn Kenyon","St. Martin's","8/23/2009","Non Fiction"},{"Bag of Bones","Stephen King","Scribner","10/11/1998","Non Fiction"},{"Beach Music","Pat Conroy","Talese/Doubleday","7/16/1995","Fiction"},{"Before I Say Goodbye","Mary Higgins Clark","Simon & Schuster","5/7/2000","Fiction"},{"Best Friends Forever","Jennifer Weiner","Atria","8/2/2009","Fiction"}};
    // Make the first index of the input title an uppercase letter by default
    title[0] = toupper(title[0]);
    for(int i = 0; i <= 39; i++){
      if(strstr(data[i][0].c_str(), title.c_str())){
        if(strstr(data[i][0].c_str(), " ")){
          int index = title.find(" ");
          toupper(index+1);
          cout << data[i][0] << ", " << data[i][1] << ", " << data[i][2] << ", " << data[i][3] << ", " << data[i][4] << endl;
        }else{
          if(strcmp(data[i][0].c_str(), title.c_str())){
            cout << data[i][0] << ", " << data[i][1] << ", " << data[i][2] << ", " << data[i][3] << ", " << data[i][4] << endl;
          }
        } 
      }
  }
}
int main(){
    // Sets option to 0 so that the variable option isn't equal to '1, 2, 3, or q'
    char option = '0';
    string bYear;
    string eYear;
    string author;
    string title;
    bool continyou = true;
    ask();
    cin >> option;

    while(continyou == true){
      if(option == '1'){
        cout << "Enter beginning year: " << flush;
          cin >> bYear;
          cout << "Enter ending year: " << flush;
          cin >> eYear;
          cout << endl;
          cout << "All titles between " << bYear << " and " << eYear << ": " << endl;
          optionOne(eYear, bYear);
          cout << endl;
          continyou == true;
          ask();
          cin >> option;
      }
              
      if(option == '2'){
        cout << "Enter an author's name: " << flush;
        cin >> author;
        optionTwo(author);
        cout << endl;
        continyou == true;
        ask();
        cin >> option;
      }
                
      if(option == '3'){
        cout << "Enter a title: ";
        cin >>  title;
        cout << endl;
        optionThree(title);
        continyou == true;
        ask();
        cin >> option;
      }
      if(option == 'q' || option == 'Q'){
        continyou = false;
      }

      else{
        cout << "Enter a valid input" << endl;
        ask();
        cin >> option;
      }
    }
        return 0;
}