print "Welcome to our multiplication tables app!"

column_number = raw_input("Please enter a column number to view ('q' to quit): ")

# Python function used for running the same code repeatedly. 
# Takes 1 argument, the column_number for a multiplication table. 
def show_multiplication_table(column_number):
    print 
    print "Table for", column_number
    print "============"
    
    # Loop through rows 1 - 12 to create a multiplication table column.
    for row in range(13):
        if row > 9:
            row_content = str(row)
        else:
            # Add a leading space for single digit numbers.
            row_content = ' ' + str(row)
        # Print out this row in the multiplication table:
        print column_number, "x", row_content, "=", row*column_number

while (column_number != 'q' and column_number != 'Q'):
    column_number = int(column_number)
    
    # Run our Python function
    show_multiplication_table(column_number)
    
    # Start the process over again, and ask for a new column_number
    print 
    column_number = raw_input("Please enter a column number to view ('q' to quit): ")

# http://repl.it/f1w/1
