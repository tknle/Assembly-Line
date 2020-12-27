# Assembly Line

## Table of Contents
* [Project Overview](#project-overview)
  * [Project Description](#project-description)
  * [Stations](#stations)
  * [Filling Order](#filling-order)
  * [Complete Filling Orders](#complete-filling-orders)
  * [Inventory](#inventory)
* [Getting Started](#getting-started)
  * [Compilation](#compilation)
  * [Author](#author)
  * [Project](#project)

## Project Overview

The project is to make a simulated Assembly Line using C++ Object Oriented skills and knowledge to implement, debug and execute the application 

## Project Description

>The project simulates an assembly line that fills customer orders from inventory. Each customer order consists of a list of items that need to be filled. The line consists of a set of stations. Each station holds an inventory of items for filling customer orders and a queue of orders to be filled. Each station fills the next order in the queue if that order requests its item and that item is still in stock. A line manager moves the customer orders from station to station until all orders have been processed. Any station that has used all of the items in stock cannot fill any more orders. Orders become incomplete due to a lack of inventory at one or more stations. At the end of all processing, the line manager lists the completed orders and the orders that are incomplete.

## Stations
Display all stations and station ID


```sh
========================================
=         Stations (summary)           =
========================================
[001] Item: CPU          [123456]
[002] Item: Memory       [654321]
[003] Item: GPU          [056789]
[004] Item: WiFi         [000887]
[005] Item: SSD          [987654]
[006] Item: Power Supply [147852]
[007] Item: Monitor      [000987]
```

## Filling Order
Filling order from customers' order. Each order has several items

```sh
========================================
=           Filling Orders             =
========================================
Line Manager Iteration: 1
    Filled Elliott C., Gaming PC [Power Supply]
Line Manager Iteration: 2
    Filled Elliott C., Gaming PC [CPU]
    Filled Chris S., Laptop [Power Supply]
Line Manager Iteration: 3
    Filled Chris S., Laptop [CPU]
    Filled Elliott C., Gaming PC [GPU]
    Filled Elliott C., Gaming PC [GPU]
    Filled Elliott C., Gaming PC [GPU]
    Filled Mary-Lynn M., Desktop PC [Power Supply]
Line Manager Iteration: 4
    Filled Mary-Lynn M., Desktop PC [CPU]
    Filled Elliott C., Gaming PC [Memory]
    Filled Chris T., Micro Controller [Power Supply]
Line Manager Iteration: 5
    Filled Chris S., Laptop [Memory]
    Filled Elliott C., Gaming PC [SSD]
Line Manager Iteration: 6
    Filled Mary-Lynn M., Desktop PC [Memory]
    Filled Chris T., Micro Controller [GPU]
    Filled Chris T., Micro Controller [GPU]
    Filled Chris S., Laptop [SSD]
    Filled Elliott C., Gaming PC [Monitor]
    Filled Elliott C., Gaming PC [Monitor]
Line Manager Iteration: 7
Line Manager Iteration: 8
    Filled Chris S., Laptop [WiFi]
    Filled Chris T., Micro Controller [SSD]
    Filled Mary-Lynn M., Desktop PC [Monitor]
Line Manager Iteration: 9
    Filled Mary-Lynn M., Desktop PC [WiFi]
Line Manager Iteration: 10
    Filled Chris T., Micro Controller [WiFi]
```

## Complete Filling Orders

```sh
========================================
=           Completed Orders           =
========================================
Elliott C. - Gaming PC
[123458] CPU              - FILLED
[654321] Memory           - FILLED
[056789] GPU              - FILLED
[056790] GPU              - FILLED
[056791] GPU              - FILLED
[987654] SSD              - FILLED
[147852] Power Supply     - FILLED
[000987] Monitor          - FILLED
[000988] Monitor          - FILLED
Chris S. - Laptop
[123459] CPU              - FILLED
[654322] Memory           - FILLED
[987655] SSD              - FILLED
[147853] Power Supply     - FILLED
[000887] WiFi             - FILLED
Mary-Lynn M. - Desktop PC
[123460] CPU              - FILLED
[654323] Memory           - FILLED
[147854] Power Supply     - FILLED
[000888] WiFi             - FILLED
[000989] Monitor          - FILLED
Chris T. - Micro Controller
[056792] GPU              - FILLED
[000889] WiFi             - FILLED
[056793] GPU              - FILLED
[147855] Power Supply     - FILLED
[987656] SSD              - FILLED
```

## Inventory
Display the inventory after filling orders

```sh
========================================
=          Inventory (full)            =
========================================
[001] Item: CPU          [123461] Quantity: 1            Description: Central Processing Unit
[002] Item: Memory       [654324] Quantity: 7            Description: Basic Flash Memory
[003] Item: GPU          [056794] Quantity: 2            Description: Graphic Processing Unit
[004] Item: WiFi         [000890] Quantity: 2            Description: Network Card with WiFi
[005] Item: SSD          [987657] Quantity: 2            Description: Solid State Drive
[006] Item: Power Supply [147856] Quantity: 16           Description: Basic AC Power Supply
[007] Item: Monitor      [000990] Quantity: 2            Description: Monitor size 32 inches, 4K

```


## Getting Started


### Compilation

1. [Click here to run on Repl.it](https://repl.it/@tknle/Assembly-Line#main.cpp)

To run this program, please type in the console:

```sh
./main Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt
```

2. If download or clone the repository, please run the following command.

```sh
g++ -Wall -std=c++17 -g -o main CustomerOrder.cpp LineManager.cpp Station.cpp Utilities.cpp Workstation.cpp main.cpp
```

3. You can also run on Visual Studio by clicking the **Final Proj.vcxproj** file

## Author

Mia Le

** To avoid plagiarism please do not copy the code. Refer to Mia Le any part of the code you copied **

## Project Link: 
[Project Link](https://github.com/tknle/Assembly-Line)
