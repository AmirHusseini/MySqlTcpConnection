This project will work just on Solution Configuration (Debug) and Solution Platform (x86).
You have to download mysql-connector-c++-8.0.22-win32, in this case i have already downloaded in the project.
You have to download Boost from (www.boost.org).

   - From Visual Studio, Project -> Properties -> Linker -> General > Additional Library Directories, add the "\lib\vs14\debug" directory (for example: C:\Program Files (x86)\MySQL\mysql-connector-c++-8.0.22-win32\lib\vs14\debug) of the C++ connector.
   - From Visual Studio, Project -> Properties -> C/C++ -> General -> Additional Include Directories:
        Add the "\include" directory of c++ connector (for example: C:\Program Files (x86)\MySQL\mysql-connector-c++-8.0.22-win32\include).
        Add the Boost library's root directory (for example: C:\boost_1_75_0).
   - From Visual Studio, Project -> Properties -> Linker -> Input > Additional Dependencies, add mysqlcppconn.lib into the text field.
  
