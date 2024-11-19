ONLINE VOTING SYSTEM

This program implements a basic Online Voting System using C. It allows users to perform the following tasks:

Register Voters: Users can add voters to the system by providing a unique ID and name.
Register Candidates: Users can add candidates to the system by providing a unique ID and name.
Cast Votes: Registered voters can cast their votes for registered candidates. The system ensures that:
Each voter can vote only once (using a hash table to track voter IDs).
Only valid candidates can receive votes.
Display Results: The system tallies the votes for each candidate and displays the election results, including the number of votes each candidate received.


**Why It Is Useful**

Automation:
Simplifies the voting process by digitizing voter and candidate registration, vote casting, and result calculation.

Integrity:
Ensures each voter can vote only once using a hash table for vote tracking.
Prevents fraudulent votes by restricting the system to registered voters and candidates.

Transparency:
Provides clear and accessible election results, showing the vote count for each candidate.

Educational Tool:
Demonstrates the use of linked lists for dynamic data management (voters and candidates).
Introduces the application of hash functions for efficient vote tracking.
Teaches basic data validation, memory management, and user interaction in C programming.

Scalability:
Can be expanded to include advanced features such as encrypted vote storage, graphical user interfaces, or multi-election support.

Real-World Applications:
Forms the foundation for electronic voting systems used in small-scale elections, organizations, or student councils.
