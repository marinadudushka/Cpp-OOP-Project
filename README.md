# Cpp-OOP-Project
# C++ OOP Practicum project 2018/2019 #
The project is a system of a shopping center. The system has different kinds of products and allows the addition of new ones. The users can register and shop online.

## Realisation: ##

The system has a list of available products and their contents, a list of current clients and a list of people working in the store(collecting orders).

## The store system allows: ##

* Adding new products
* Adding a new client
* Adding staff
* Removing a product
* Selling existing and in stock products
* Saving the product information in a data base( in this case a file)

## Clients can: ##
* Buy products
* Receive information for a product 
* Receive information for all products of a category 
* Receive information for all products

## The staff can: ##
* Collect and fulfill orders.

## The system has four product categories: ##
* Food
* Clothing
* Technology
* Cosmetics
* Each of the product types have information about them.

## Execution of task: ##

* Abstract class Product that is a base class for all product categories
* Four classes, inheriting the Product class for each product category, which have unique information about said products.
* Class Person - base class to be inherited by class Client and class Worker.
* Class System having a dynamic array for the products, array for clients and array for workers.
* The systems allow for admin login - only the admin can add and remove products.

