**ONLINE VOTING SYSTEM**

Voter and Candidate Registration:
  Allows registering voters and candidates with unique IDs and names.
Ensures voters cannot register multiple times using the same ID.

Vote Casting with Validation:
  Ensures only registered voters can cast a vote.
Prevents voters from voting more than once using a hash table for tracking.

Dynamic Data Management:
  Uses linked lists to dynamically manage voters and candidates, supporting an unlimited number of entries.

Result Display:
  Displays each candidate's vote count after voting is complete.
Announces the winner or identifies a tie if votes are equal.

Error Handling and Security:
  Validates voter and candidate IDs during operations.
Hash-based tracking ensures integrity by preventing duplicate votes.



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
