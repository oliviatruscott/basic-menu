/*

natasha fernando                    CS 11                           THURSTON

Temperature Conversion - Name this function tempConvert. The function data type 
should be double and it should take two int parameters.  One for the temperature 
to convert, and one to indicate conversion to Celsius from Fahrenheit (value = 0), 
or to Fahrenheit from Celsius (value = 1). Collect the parameters in the case statement. 
You'll need to modify the user prompt for this function. Display the result.
*/

double tempConvert(int temp1, int isF2C)
{
    if (isF2C == 0) {
        return (temp1 - 32)*5/9.0; // Fahrenheit to Celsius
    }
    else {
        return (temp1 * (9.0/5.0)) + 32; // Celsius to Fahrenheit
    }
}