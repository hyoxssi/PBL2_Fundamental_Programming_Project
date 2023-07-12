# PBL2_Fundamental_Programming_Project
This is a Fundamental Programming Project carried out by myself in the first term of Second year studying in Danang University of Science an Technology.

The program uses the object-oriented programming paradigm to build a movie ticket booking management system using the C++ programming language for completion. This is a console application with a simple and user-friendly interface.

The 'database' folder contains:
1. Files 'CGV', 'LOTTE', 'METIZ', where the first line of each file contains the official name of the cinema chain, the second line contains the password for cinema management login, the third line contains the number of active theaters in the chain, the fourth line contains the number of employees working in the chain, and the last lines contain information about the number of rows and columns of seats in each theater within the chain, as well as information about the employees in each cinema chain.
2. Files 'CinemaOfCGV1', 'CinemaOfLOTTE3', 'CinemaOfMETIZ4' contain information about the theaters within the cinema chain. The first line contains the number of rows and columns of seats in the theater, and the following lines contain the seating matrix of the theater, where 0 represents an empty seat and 1 represents a pre-booked seat.
3. The 'Customer' file contains the number of registered customers on the system in the first line, followed by the information of each customer on subsequent lines, separated by commas.
4. The 'Movie' file contains the number of movies currently being screened in the first line, followed by information about each movie, including the movie title, rating, director, actors, and genre.
5. The 'Showtimes' file contains the screening schedule for each movie.

The 'main' folder contains the source files organizing the system's objects used in the program, along with the 'main' file, which is the main execution file of the program.

The program allows users to log in as either cinema management or customers. As cinema management, users can view the list of customers. As customers, users can book movie tickets at the cinemas listed in the database.
