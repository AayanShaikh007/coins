Theme: Coins (currency?)
Idea: Budget App

Potential Features: 
1. income page
2. expense page
3. reports page

# October 1st 2025
Today I spent my time deciding what project I wanted to make that fits within the theme of currency or coins. As a first year student in university, I quickly realized that there are so many expenses that we make on a daily basis, and it is important to keep track of these expenses to see any trends and keep spending in check. Considering how problematic student debt is in the U.S. and Canada, keeping a budget seems to be an essential for every student.

**The Project:**  
I decided to make a terminal based budget tracking app, tailored towards students. It will allow you to record your expenses and categorize them, or see trends in spending habits. 

Although Python would be better suited to this sort of app, I am going to try coding it in C to gain more experience in it.

 
Functionalities:

- Data will be saved to the local drive to make the app more practical to use. 
- Data Record Mode: allows for new expenses to be recorded, keeping track of date, category, and necessity. 
- Data View Mode: reveals information about the expenses over the past (month?), and giving suggestions to reduce spending (ex. you spent a total of $120 on restaurants, meal prep will save you (x) dollars per month)
- On program startup, there will also be a short dialogue about spending habits prompting user to enter Data view mode.   

**List is Subject to change**

# October 4th 2025

Today I will start making the Data Record functionality, I will work on data saving once I have a proof of concept of the data record functionality. 

I have a minimum working product of the Data Record Mode. The program asks for the user to enter the exact amount they spent, asks them to specify the category it fits into, and asks for the date of the transaction (defaults to the present day). I also added the data saving feature because I was working with the data that needed to be saved. Next, I will work on the Data View Mode. 

I finished some of the data view mode, for example, I added a method to read all data from the text file and display the transactions to the user. 

# October 5th 2025

Today I finished adding the first method of the data view mode. I wanted to add a feature to the data view mode that would format/sort the txt file. The data.txt needs to be sorted by date for other aforementioned features as well. 

I have now finished the data.txt file sort functionality. Part of the functionality needed to efficiently parse through the code to sort it by date. I used AI here for a bubble sort implementation. I also modifed the code so that it continuously asks/waits for input and doesnt need to be restarted. 

Next, I will be adding a feature to analyze expenses over the past 30 days. This function should be able to select transactions in the last 30 days, see their categories and return a number of suggestions back to the user.

refined brainstorming/to do list: 
- add insights
- if time use python for visualization
- graphs?
- add necessity value to list 