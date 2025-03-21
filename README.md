The Electricity Bill Generator System is a simple C program designed to manage and calculate electricity bills based on meter readings. The system allows users to input meter readings, calculate the bill based on Nepal's electricity tariff rates, modify existing records, and display stored readings. This system is particularly designed for 5 Ampere meters and aims to help users track their electricity consumption efficiently.

FEATURES
•	Insert New Reading: Users can input meter ID, units consumed, and the date of the reading.
•	Automatic Bill Calculation: The system calculates the bill based on predefined tariff rates.
•	Modify Existing Readings: Users can update the meter readings and bill calculations accordingly.
•	Display All Readings: Shows all recorded meter readings along with the bill amount and date.
•	Doubly Linked List Implementation: Efficient data storage and retrieval.
•	
WORKING MECHANISM
1.	The user selects an option from the menu.
2.	If adding a new reading, the user inputs meter ID, units consumed, and date.
3.	The program calculates the bill using calculateBill().
4.	Data is stored in a doubly linked list for easy access and modification.
5.	The user can display, modify, or exit the system as needed.


BILL CALCULATION LOGIC

•	Up to 20 units: Free consumption, service charge Rs. 30.
•	21-30 units: Rs. 3 per unit for first 20 units, Rs. 6.5 for remaining, service charge Rs. 50.
•	31-50 units: Additional Rs. 8 per unit, service charge Rs. 50.
•	51-100 units: Additional Rs. 9.5 per unit, service charge Rs. 75.
•	101-250 units: Additional Rs. 9.5 per unit, service charge Rs. 100.
•	Above 250 units: Additional Rs. 11 per unit, service charge Rs. 150.

ADVANTAGES
•	Helps in tracking electricity consumption efficiently.
•	Provides transparency in billing.
•	Can be extended to store and retrieve readings from a database.
•	Basic implementation of data structures (linked lists) in C.

