#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/* =========================================================
   🔥 FUNCTION DECLARATIONS (CORE INTERFACE)
   =========================================================
   This section defines all major functions used in the program.
   These functions handle:
   - Input processing
   - Arithmetic operations (Add, Subtract, Multiply, Divide)
   - Large number handling using digit arrays

   NOTE:
   These are only declarations (prototypes).
   Actual implementations are defined later in the code.
   ========================================================= */
/*
 * Function: read_digit_arrays
 * ---------------------------
 * Reads two numeric inputs as strings, converts them into digit arrays,
 * calculates their lengths, and reads the arithmetic operation type.
 *
 * Parameters:
 *  first_number_digits  : Output array to store digits of first number
 *  second_number_digits : Output array to store digits of second number
 *  count_a              : Pointer to store length of first number
 *  count_b              : Pointer to store length of second number
 *  type                 : Pointer to store operation type (A/M/S/D)
 */
void read_digit_arrays(int *first_number_digits,
                       int *second_number_digits,
                       int *count_a,
                       int *count_b,char *type);
/*
 * Function: divide_digit_arrays
 * -----------------------------
 * Performs division of two large numbers represented as digit arrays.
 * Computes quotient and remainder using manual arithmetic logic.
 *
 * Parameters:
 *  dividend_digits      : Digit array of dividend
 *  divisor_digits       : Digit array of divisor
 *  result_buffer        : Buffer to store result (ASCII string)
 *  dividend_digit_count : Number of digits in dividend
 *  divisor_digit_count  : Number of digits in divisor
 */
void divide_digit_arrays(int *dividend_digits,
                         int *divisor_digits,
                         char *result_buffer,
                         int dividend_digit_count,
                         int divisor_digit_count);
/*
 * Function: add_digit_arrays
 * --------------------------
 * Adds two numbers represented as digit arrays and stores the result
 * as an ASCII string in result_buffer.
 *
 * Parameters:
 *  first_number_digits  : Digit array of first number
 *  second_number_digits : Digit array of second number
 *  result_buffer        : Output buffer to store sum
 *  first_digit_count    : Number of digits in first number
 *  second_digit_count   : Number of digits in second number
 */
void add_digit_arrays(int *first_number_digits,
                      int *second_number_digits,
                      char *result_buffer,
                      int first_digit_count,
                      int second_digit_count);
/*
 * Function: subtract_digit_arrays
 * -------------------------------
 * Subtracts two numbers represented as digit arrays and stores the
 * result in ASCII format.
 *
 * Parameters:
 *  first_number_digits  : Digit array of first number
 *  second_number_digits : Digit array of second number
 *  result_buffer        : Output buffer to store difference
 *  first_digit_count    : Number of digits in first number
 *  second_digit_count   : Number of digits in second number
 */
void subtract_digit_arrays(int *first_number_digits,
                           int *second_number_digits,
                           char *result_buffer,
                           int first_digit_count,
                           int second_digit_count);
/*
 * Function: multiply_digit_arrays
 * -------------------------------
 * Multiplies two large numbers represented as digit arrays and stores
 * the result as an ASCII string.
 *
 * Parameters:
 *  first_number_digits  : Digit array of first number
 *  second_number_digits : Digit array of second number
 *  result_buffer        : Output buffer to store product
 *  first_digit_count    : Number of digits in first number
 *  second_digit_count   : Number of digits in second number
 */
void multiply_digit_arrays(int *first_number_digits,
                           int *second_number_digits,
                           char *result_buffer,
                           int first_digit_count,
                           int second_digit_count);
/* =========================================================
   SPECIAL / UTILITY FUNCTION DECLARATIONS
   ========================================================= */
/*
 * Function: multi_digit_50_counter
 * --------------------------------
 * 🔥 HIGHLIGHT FUNCTION
 *
 * Implements a multi-digit decimal counter that can count
 * up to 50 digits (very large numbers).
 *
 * Each function call increments the counter by 1.
 * Works like:
 *   1 → 2 → 3 → ... → 999... (up to 50 digits)
 *
 * Parameters:
 *  used_digit_count : Pointer to store number of active digits
 *
 * Returns:
 *  Pointer to static array containing current counter digits
 *
 * Notes:
 *  - Uses static memory (persists across calls)
 *  - Used mainly in division logic for iterative multiplication
 */
static int * multi_digit_50_counter(int *used_digit_count);
/*
 * Function: remove_leading_zeros
 * ------------------------------
 * Removes leading '0' characters or NULL values from a buffer
 * by shifting elements to the left.
 *
 * Parameters:
 *  buffer : Character array containing numeric string
 *
 * Notes:
 *  - Modifies buffer in-place
 *  - Designed for fixed-size buffers
 */
static void remove_leading_zeros(char *buffer);
/*
 * Function: convert_string_digits_to_int_array
 * --------------------------------------------
 * Converts a numeric string into an integer digit array.
 *
 * Example:
 *   "1234" → {1,2,3,4}
 *
 * Parameters:
 *  input_str     : Input string (ASCII digits)
 *  output_digits : Output integer array
 */
static void convert_string_digits_to_int_array(char *input_str, int *output_digits);
/*
 * Function: invalid_num_validate
 * ------------------------------
 * Validates whether the digit array contains only valid digits (0–9).
 *
 * Parameters:
 *  first_number_digits : Digit array to validate
 *  count               : Pointer to number of digits
 *
 * Returns:
 *  0 → Valid number
 *  1 → Invalid number
 */
static int invalid_num_validate(int *first_number_digits, int *count);
/*
 * Function: int_to_string
 * -----------------------
 * Converts integer digit array into ASCII string format.
 *
 * Example:
 *   {1,2,3} → "123"
 *
 * Parameters:
 *  num : Input integer digit array
 *  str : Output character string
 */
static void int_to_string(int *num,char *str);
/*
 * Function: string_length
 * -----------------------
 * Calculates the length of a null-terminated string.
 *
 * Parameters:
 *  str : Input string
 *
 * Returns:
 *  Length of string (excluding '\0')
 */
static int string_length(char *str);
/* ================= MACROS ================= */
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FIVE 5
#define NINE 9
#define TEN 10
#define ELEVEN 11
#define FORTY_EIGHT 48
#define FORTY_NINE 49
#define FIFTY 50
#define FIFTY_ONE 51
/******************************************************************************
 * @brief   Converts numeric string characters into an integer digit array.
 *
 * @details
 * This function iterates through the input string and converts each ASCII
 * character ('0'–'9') into its corresponding integer value by subtracting
 * the ASCII base value (48). The converted digits are stored in the
 * provided integer array.
 *
 * The function processes up to 10 characters. It assumes that the input
 * string contains only valid numeric characters.
 *
 * @param[in]  input_str       Pointer to the input string containing digits.
 * @param[out] output_digits   Pointer to the integer array where converted
 *                            digits will be stored.
 *
 * @note
 * - The function does not handle non-numeric characters.
 * - The loop runs for a fixed size (10 elements).
 * - Null termination check is present but not implemented correctly
 *   due to logical condition usage.
 *
 * @return
 *          None
 *
 ******************************************************************************/
static void convert_string_digits_to_int_array(char *input_str, int *output_digits)
{
    int index = ZERO;   // Loop counter

    for (index = ZERO; index < TEN; index++)
    {
        if (*(input_str + index) != (NULL||'\0'))   // Check for null terminator
        {
            /*
             * ASCII to integer conversion
             * '0' = 48 in ASCII
             */
            *(output_digits + index) = (int)*(input_str + index) - FORTY_EIGHT;
        }
    }


}
/******************************************************************************
 * @brief   Converts integer digits into their ASCII string representation.
 *
 * @details
 * This function converts integer values into their corresponding ASCII
 * character representation by adding an offset of 48 (ASCII value of '0').
 * The converted characters are intended to form a null-terminated string.
 *
 * The conversion is performed iteratively until a null terminator ('\0')
 * is encountered in the string buffer.
 *
 * @param[in]  num   Pointer to the integer array containing digit values.
 * @param[out] str   Pointer to the character array where the resulting
 *                  string will be stored.
 *
 * @note
 * - Each integer digit (0–9) is converted to its ASCII equivalent by adding 48.
 * - The output buffer must be pre-allocated and properly initialized.
 * - The function assumes the presence of a null terminator for loop control.
 * - The macro FORTY_EIGHT should represent ASCII value 48.
 * - The function does not handle multi-digit numbers directly, only individual digits.
 *
 * @return
 *          None
 *
 ******************************************************************************/
static void int_to_string(int *num,char *str)
{
    int index=ZERO;
    while(str[index]!='\0')
    {
        *(num+index)=*(str+index)+FORTY_EIGHT;
    }

}
/******************************************************************************
 * @brief   Calculates the length of a null-terminated string.
 *
 * @details
 * This function computes the number of characters present in the
 * input string by iterating through each character until the
 * null terminator ('\0') is encountered.
 *
 * A counter is incremented for each valid character, and the
 * final count represents the string length (excluding the
 * null terminator).
 *
 * @param[in]  str   Pointer to the input null-terminated character string.
 *
 * @return
 *          int  -> Number of characters in the string (excluding '\0')
 *
 * @note
 * - The input string must be properly null-terminated.
 * - The macro ZERO should be defined as 0.
 * - The function includes a printf statement for debugging purposes,
 *   which may not be suitable for embedded or production environments.
 *
 ******************************************************************************/
static int string_length(char *str)
{
    int index=ZERO;
    while(*(str+index)!='\0')
    {
        index++;
    }
    printf("Index :%d",index);
    return index;
}
/******************************************************************************/
/*************************SPECIAL COUNTER, COUNT UPTO 2^50********************/
/******************************************************************************
 * @brief   Implements a multi-digit decimal counter (up to 50 digits).
 *
 * @details
 * This function maintains and increments a decimal counter where each
 * digit ranges from 0 to 9, similar to a standard multi-digit number.
 * On each function call, the counter value is incremented by one,
 * handling carry propagation across digits.
 *
 * The counter supports up to 50 digits, and only the active digits
 * are considered. Before returning, the active digits are aligned
 * to the beginning of the array.
 *
 * @param[in,out]  used_digit_count   Pointer to the variable that holds
 *                                   the number of digits currently in use.
 *
 * @return
 *          int*  -> Pointer to the static array containing counter digits
 *
 * @note
 * - The function uses static memory; values persist across function calls.
 * - The counter increments on each invocation of the function.
 * - Maximum supported digit count is 50.
 * - The caller should not modify the returned pointer directly.
 *
 ******************************************************************************/
 /****************************************************************************/
/*****************************************************************************/
static int * multi_digit_50_counter(int *used_digit_count)
{
    static int counter_digits[FIFTY] = {ZERO};   // Stores 50-digit counter

    int digit_index = FORTY_NINE;      // Index of least significant digit (LSD)
    int reset_index = ZERO;       // Used during digit reset
    int loop_index = ZERO;        // General loop variable
    int shift_index = ZERO;       // Index for rearranging active digits

    static int current_digit_value = ZERO;    // Current increment value
    static int active_digit_count = ONE;     // Number of digits currently active

    while (current_digit_value <= TEN)
    {
        // Assign value to least significant digit
        counter_digits[digit_index] = current_digit_value;

        // Carry handling when digit exceeds 9
        if (current_digit_value == TEN)
        {
            current_digit_value = ZERO;

            // Traverse digits from LSD to MSD for carry propagation
            for (digit_index = FORTY_NINE; digit_index >= ZERO; digit_index--)
            {
                if (counter_digits[digit_index] == TEN)
                {
                    // Reset overflowing digit
                    for (reset_index = digit_index; reset_index >= digit_index; reset_index--)
                    {
                        counter_digits[reset_index] = ZERO;
                    }

                    // Increment next higher digit
                    if (counter_digits[reset_index] <= TEN && reset_index >= ZERO)
                    {
                        counter_digits[reset_index] =
                            counter_digits[reset_index] + ONE;

                        // Update active digit count
                        active_digit_count = (FIFTY - reset_index);
                    }

                    // Boundary protection (logic preserved as-is)
                    if (reset_index < ZERO)
                    {
                        counter_digits[reset_index + ONE] = NINE;
                    }
                }
                else
                {
                    // No carry required
                    break;
                }
            }
        }

        // Track maximum digits used so far
        if (*used_digit_count < active_digit_count)
        {
            *used_digit_count = active_digit_count;
        }

        // Shift active digits to the beginning of the array
        shift_index = ZERO;
        for (loop_index = (FIFTY - *used_digit_count); loop_index < FIFTY; loop_index++)
        {
            counter_digits[shift_index] = counter_digits[loop_index];
            shift_index++;
        }

        // Prepare for next increment
        current_digit_value++;

        // Return pointer to static counter array
        return counter_digits;
    }
}
/******************************************************************************
 * @brief   Removes leading zeros and null characters from a buffer.
 *
 * @details
 * This function removes leading ASCII '0' characters and null characters
 * ('\0') from a fixed-size character buffer by shifting the contents
 * towards the left. The operation continues until the first character
 * in the buffer is neither '0' nor '\0'.
 *
 * The function performs the operation in-place without using any
 * additional memory.
 *
 * @param[in,out]  buffer   Pointer to the character array (fixed-size buffer)
 *                         to be modified.
 *
 * @return
 *          None
 *
 * @note
 * - The function assumes a fixed buffer size (e.g., 10 characters).
 * - It modifies the original buffer directly.
 * - Not intended for general-purpose null-terminated strings.
 * - Care should be taken to ensure buffer boundaries are respected.
 *
 ******************************************************************************/
static void remove_leading_zeros(char *buffer)
{
    int index = ZERO;   // Loop counter for shifting elements

    // Remove leading null or '0' characters
    while (*(buffer + ZERO) == ZERO || buffer[ZERO] == '0')
    {
        // Shift all elements one position to the left
        for (index = ZERO; index < TEN; index++)
        {
            *(buffer + index) = *(buffer + (index + ONE));
        }
    }

    return 0;   // Preserved as-is (even though function is void)
}
/******************************************************************************
 * @brief   Validates whether the given digit array forms a valid number.
 *
 * @details
 * This function checks whether each digit in the input array matches
 * values between 0 and 9 sequentially. If any digit exceeds valid
 * numeric range or validation fails, it prints "Invalid Number"
 * and returns 1.
 *
 * @param[in]  first_number_digits   Pointer to array containing digits.
 * @param[in]  count                 Pointer to total number of digits.
 *
 * @return
 *          0  -> Valid number
 *          1  -> Invalid number
 *
 ******************************************************************************/
static int invalid_num_validate(int *first_number_digits, int *count)
{
    int validate = 0;   /* Index used to validate digits */
    int i = 0;          /* Loop variable */

    /* Loop through digits and check validity */
    for (i = 0; i < 10; i++)
    {
        /* If all digits are validated successfully */
        if (validate == *count)
        {
            break;
        }
        /* If digit exceeds valid numeric range (0-9) */
        else if (i == 10)
        {
            printf("Invalid Number\n");
            return 1;
        }
        /* If current digit matches expected value */
        else if (i == *(first_number_digits + validate))
        {
            validate++;   /* Move to next digit */
            i = 0;       /* Reset loop (will become 0 after increment) */
        }
    }

    return 0;   /* Number is valid */
}
/******************************************************************************
 * @brief   Reads numeric inputs, converts them into digit arrays, and
 *          determines the operation type.
 *
 * @details
 * This function reads two numeric inputs from standard input as strings,
 * calculates their lengths, and converts each character into individual
 * integer digits stored in separate arrays.
 *
 * It validates both converted digit arrays to ensure they represent valid
 * numeric values. If validation succeeds, it reads an operation type
 * (such as '+', '-', etc.). If validation fails, the operation type is
 * set to 'E' to indicate an error.
 *
 * @param[out] first_number_digits   Pointer to array storing digits of
 *                                  the first number.
 * @param[out] second_number_digits  Pointer to array storing digits of
 *                                  the second number.
 * @param[out] count_a               Pointer to variable holding digit count
 *                                  of the first number.
 * @param[out] count_b               Pointer to variable holding digit count
 *                                  of the second number.
 * @param[out] type                  Pointer to character storing the
 *                                  operation type.
 *
 * @return
 *          None
 *
 * @note
 * - Input is read using scanf with a maximum limit of 9 characters.
 * - The function assumes valid numeric string input format.
 * - Conversion from string to digit array is handled by
 *   convert_string_digits_to_int_array().
 * - Validation is performed using invalid_num_validate().
 * - If validation fails, the operation type is set to 'E'.
 * - Debug print statements (printf) are present and may not be suitable
 *   for embedded or production environments.
 *
 ******************************************************************************/
void read_digit_arrays(int *first_number_digits,
                       int *second_number_digits,
                       int *count_a,
                       int *count_b,char *type)
{

    char st1[11]= {0},st2[11]= {0};
    int error = 0;
//int8_t validate =0,i=0;
    /* Read first number as string */
    //scanf("%9s", &st1);
    scanf("%50s", st1);
    printf("s1: %s\n", st1);
    *count_a = string_length(st1);
    printf("count_1: %d\n", *count_a);
    // Convert string to integer.
    convert_string_digits_to_int_array(st1, first_number_digits);
    /*
    for(i=0;i=10;i++)
    {
        if(validate==(*count_a-1))
        {
            break;
        }else if(i==10){
            printf("Invalid Number:");
            break;
        i=0;}elseif(i==*(first_number_digits+validate)){
        validate++;
        i=0;
        }
    }
    */
    error = invalid_num_validate(first_number_digits,count_a);
    /* Read second number as string */
   // scanf("%9s", &st2);
    scanf("%50s", st2);
    printf("s2: %s\n", st2);
    *count_b = string_length(st2);
   // printf("count_2: %d\n", count_b);
    // here we convert string to integer perfectly done,
    convert_string_digits_to_int_array(st2, second_number_digits);
    /* Read operation type */
    error =  invalid_num_validate(second_number_digits,count_b);
    if(error==0)
    {
        scanf(" %c", type);   // Space before %c is IMPORTANT

    }
    else
    {
        *type = 'E';
    }

}

/******************************************************************************
 * @brief   Adds two multi-digit numbers represented as digit arrays.
 *
 * @details
 * This function performs addition of two large numbers where each number
 * is represented as an array of individual digits. The addition is carried
 * out manually in a manner similar to standard decimal addition:
 *
 * - Digits are processed from least significant to most significant.
 * - Carry is generated and propagated across digits as required.
 *
 * The final result is converted into its ASCII representation and stored
 * in the provided result buffer as a null-terminated string.
 *
 * @param[in]  first_number_digits    Pointer to the digit array of the first number.
 * @param[in]  second_number_digits   Pointer to the digit array of the second number.
 * @param[out] result_buffer          Pointer to the character buffer where the
 *                                   resulting sum will be stored as a string.
 * @param[in]  first_digit_count      Number of digits in the first number.
 * @param[in]  second_digit_count     Number of digits in the second number.
 *
 * @return
 *          None
 *
 * @note
 * - The function supports multi-digit numbers based on allocated buffer sizes.
 * - Intermediate calculations may use dynamic memory.
 * - The result is stored as a null-terminated ASCII string.
 * - Leading zeros in the result may be removed using remove_leading_zeros().
 * - The caller must ensure sufficient memory is allocated for result_buffer.
 *
 ******************************************************************************/
void add_digit_arrays(int *first_number_digits,
                      int *second_number_digits,
                      char *result_buffer,
                      int first_digit_count,
                      int second_digit_count)

{
    int digit_index;             /* Loop counter */
    int carry = ZERO;               /* Carry generated during addition */
    int result_index = NINE;        /* Result buffer index (LSD → MSD) */
    int longer_number_flag = ZERO;  /* Indicates which number is longer */
    int max_loop_index = ZERO;      /* Loop limit based on longer number */

    /* Temporary buffer to store numeric result digits */
    int *temp_digit_buffer = (int *)calloc(FIFTY, sizeof(int));

    /* Allocation failure check */
    if (temp_digit_buffer == NULL)
    {
        return;
    }

    /* Determine which input number has more digits */
    if (first_digit_count > second_digit_count)
    {
        longer_number_flag = ZERO;               /* First number is longer */
        max_loop_index = first_digit_count - ONE;
        second_digit_count--;
    }
    else
    {
        longer_number_flag = ONE;               /* Second number is longer or equal */
        max_loop_index = second_digit_count - ONE;
        first_digit_count--;
    }

    /* Perform digit-wise addition */
    switch (longer_number_flag)
    {
    case 0:
        /* First number has more digits */
        for (digit_index = max_loop_index; digit_index >= ZERO; digit_index--)
        {
            temp_digit_buffer[result_index] =
                *(first_number_digits + digit_index) +
                *(second_number_digits + second_digit_count) +
                carry;

            /* Handle carry */
            if (temp_digit_buffer[result_index] >= FIFTY)
            {
                carry = temp_digit_buffer[result_index] / FIFTY;
                temp_digit_buffer[result_index] %= FIFTY;
            }
            else
            {
                carry = ZERO;
            }

            result_index--;
            second_digit_count--;

            /* Copy remaining digits from first number */
            while ((second_digit_count < ZERO) && (digit_index > ZERO))
            {
                digit_index--;
                temp_digit_buffer[result_index] =
                    *(first_number_digits + digit_index);
                result_index--;

                if (digit_index == ZERO)
                {
                    break;
                }
            }
        }
        break;

    case 1:
        /* Second number has more digits */
        for (digit_index = max_loop_index; digit_index >= ZERO; digit_index--)
        {
            temp_digit_buffer[result_index] =
                *(first_number_digits + first_digit_count) +
                *(second_number_digits + digit_index) +
                carry;

            /* Handle carry */
            if (temp_digit_buffer[result_index] >= FIFTY)
            {
                carry = temp_digit_buffer[result_index] / FIFTY;
                temp_digit_buffer[result_index] %= FIFTY;
            }
            else
            {
                carry = ZERO;
            }

            result_index--;
            first_digit_count--;

            /* Copy remaining digits from second number */
            while (first_digit_count < ZERO && digit_index > ZERO)
            {
                digit_index--;
                temp_digit_buffer[result_index] =
                    *(second_number_digits + digit_index);
                result_index--;

                if (digit_index == ZERO)
                {
                    break;
                }
            }
        }
        break;

    default:
        printf("Invalid\n");
    }

    /* Store final carry if present */
    if (carry != ZERO)
    {
        temp_digit_buffer[result_index] = carry;
    }

    /* Convert numeric digits to ASCII characters */
    for (digit_index = NINE; digit_index >= ZERO; digit_index--)
    {
        *(result_buffer + digit_index) =
            temp_digit_buffer[digit_index] + '0';
    }

    /* Free temporary buffer */
    free(temp_digit_buffer);

    /* Remove leading zeros from result */
    remove_leading_zeros(result_buffer);
    printf("ADD :%s",result_buffer);
}

/******************************************************************************
 * @brief   Multiplies two multi-digit numbers represented as digit arrays.
 *
 * @details
 * This function performs multiplication of two large numbers where each
 * number is represented as an array of individual digits. The multiplication
 * is carried out using the traditional long multiplication method:
 *
 * - Each digit of the second number is multiplied with the first number.
 * - Intermediate partial products are generated and accumulated.
 * - Carry is properly handled and propagated across all digit operations.
 *
 * The final result is converted into its ASCII representation and stored
 * in the provided result buffer as a null-terminated string.
 *
 * @param[in]  first_number_digits    Pointer to the digit array of the first number.
 * @param[in]  second_number_digits   Pointer to the digit array of the second number.
 * @param[out] result_buffer          Pointer to the character buffer where the
 *                                   resulting product will be stored as a string.
 * @param[in]  first_digit_count      Number of digits in the first number.
 * @param[in]  second_digit_count     Number of digits in the second number.
 *
 * @return
 *          None
 *
 * @note
 * - Supports multi-digit numbers (e.g., up to 50 digits based on buffer size).
 * - Uses dynamic memory for intermediate digit storage.
 * - The result is stored as a null-terminated ASCII string.
 * - Leading zeros in the result may be removed using remove_leading_zeros().
 * - The caller must ensure sufficient memory is allocated for result_buffer.
 *
 ******************************************************************************/
void multiply_digit_arrays(int *first_number_digits,
                           int *second_number_digits,
                           char *result_buffer,
                           int first_digit_count,
                           int second_digit_count)
{
    /* Index for traversing second number digits (right to left) */
    int second_digit_index = second_digit_count - ONE;

    /* Index for traversing first number digits */
    int first_digit_index;

    /* Index for storing result digits */
    int result_digit_index;

    /* Current result position (right to left) */
    int result_position;

    /* Temporary product value */
    int product_temp = ZERO;

    /* Carry from addition of partial products */
    int add_carry = ZERO;

    /* Carry from digit multiplication */
    int multiply_carry = ZERO;

    /* Temporary digit buffer for numeric computation */
    int *temp_digit_buffer = (int *)calloc(FIFTY, sizeof(int));

    /* Clear output buffer */
    memset(result_buffer, '\0', FIFTY_ONE * sizeof(char));

    /* Check memory allocation */
    if (temp_digit_buffer == NULL)
    {
        printf("Error\n");
        return;
    }

    /* Loop through each digit position of result */
    for (result_position = FORTY_NINE; result_position >= ZERO; result_position--)
    {
        result_digit_index = result_position;

        /* Multiply current digit of second number with first number */
        for (first_digit_index = first_digit_count - ONE;
                first_digit_index >= ZERO;
                first_digit_index--)
        {
            /* Multiply digits and add carry */
            product_temp =
                *(first_number_digits + first_digit_index) *
                (*(second_number_digits + second_digit_index)) +
                multiply_carry;

            /* Handle multiplication carry */
            if (product_temp / FIFTY != ZERO)
            {
                multiply_carry = product_temp / FIFTY;
                product_temp = product_temp % FIFTY;
            }
            else
            {
                multiply_carry = ZERO;
            }

            /* Add partial product into result buffer */
            temp_digit_buffer[result_digit_index] =
                temp_digit_buffer[result_digit_index] +
                product_temp +
                add_carry;

            /* Handle addition carry */
            if (temp_digit_buffer[result_digit_index] / FIFTY != ZERO)
            {
                add_carry = temp_digit_buffer[result_digit_index] / FIFTY;
                temp_digit_buffer[result_digit_index] =
                    temp_digit_buffer[result_digit_index] % FIFTY;
            }
            else
            {
                add_carry = ZERO;
            }

            /* Handle most significant digit carry */
            if (first_digit_index == ZERO)
            {
                temp_digit_buffer[result_digit_index - ONE] =
                    add_carry + multiply_carry;
                break;
            }

            result_digit_index--;
        }

        /* Move to next digit of second number */
        second_digit_index--;

        /* Reset carries for next iteration */
        multiply_carry = ZERO;
        add_carry = ZERO;

        /* Stop if all digits of second number are processed */
        if (second_digit_index < ZERO)
        {
            break;
        }
    }

    /* Convert numeric digits to ASCII characters */
    for (first_digit_index = FORTY_NINE; first_digit_index >= ZERO; first_digit_index--)
    {
        *(result_buffer + first_digit_index) =
            *(temp_digit_buffer + first_digit_index) + '0';

        if (first_digit_index < result_digit_index)
        {
            break;
        }
    }

    /* Free temporary buffer */
    free(temp_digit_buffer);

    /* Remove leading zeros from result */
    remove_leading_zeros(result_buffer);

    printf("Mux : %s",result_buffer);
}
/******************************************************************************
 * @brief   Subtracts two multi-digit numbers represented as digit arrays.
 *
 * @details
 * This function performs subtraction of two large numbers where each number
 * is represented as an array of individual digits. Prior to subtraction,
 * the function determines the larger number to ensure correct operation.
 *
 * The subtraction is carried out digit-by-digit from least significant
 * to most significant, with proper borrow handling across digits.
 *
 * The intermediate numeric result is stored in a temporary buffer, then
 * converted into its ASCII representation and stored in the provided
 * result buffer as a null-terminated string.
 *
 * @param[in]  first_number_digits    Pointer to the digit array of the first number.
 * @param[in]  second_number_digits   Pointer to the digit array of the second number.
 * @param[out] result_buffer          Pointer to the character buffer where the
 *                                   resulting difference will be stored as a string.
 * @param[in]  first_digit_count      Number of digits in the first number.
 * @param[in]  second_digit_count     Number of digits in the second number.
 *
 * @return
 *          None
 *
 * @note
 * - Each array element represents a single digit (0–9).
 * - The function determines the larger number before performing subtraction.
 * - Borrow handling is implemented for correct digit-wise subtraction.
 * - The result is stored as a null-terminated ASCII string.
 * - Leading zeros in the result may be removed manually or using
 *   remove_leading_zeros().
 * - The caller must ensure sufficient memory is allocated for result_buffer.
 *
 ******************************************************************************/
void subtract_digit_arrays(int *first_number_digits,
                           int *second_number_digits,
                           char *result_buffer,
                           int first_digit_count,
                           int second_digit_count)

{
    /* Index variables for digit traversal */
    int first_index = ZERO;
    int second_index = ZERO;

    /* Index for result buffer (fixed size: 10 digits) */
    int result_index = NINE;

    /* Flag to identify larger number
     * 0 -> first number is larger
     * 1 -> second number is larger
     */
    int larger_number_flag = -1;

    /* Controls how many result digits to copy */
    int result_loop_limit = -1;

    //Negative Number Identification
    /*
    for(int index  = 0;index<first_digit_count;index++){
         if (*(first_number_digits + first_index) <
                    *(second_number_digits + first_index)){
                    //sign -
                    break;
                    }
                    if (*(first_number_digits + first_index) >
                    *(second_number_digits + first_index)){
                    //sign +
                    break;
                    }
    }
    */
    /* Case 1: Both numbers have same digit count */
    if (first_digit_count == second_digit_count)
    {
        while (first_index < first_digit_count)
        {
            /* First number is larger */
            if (*(first_number_digits + first_index) >
                    *(second_number_digits + first_index))
            {
                first_index = first_digit_count - ONE;
                second_index = second_digit_count - ONE;
                larger_number_flag = ZERO;
                result_loop_limit = first_digit_count - ONE;
                break;
            }

            /* Second number is larger */
            if (*(first_number_digits + first_index) <
                    *(second_number_digits + first_index))
            {
                first_index = second_digit_count - ONE;
                second_index = first_digit_count - ONE;
                larger_number_flag = ONE;
                result_loop_limit = second_digit_count - ONE;
                break;
            }

            /* Digits are equal, move to next digit */
            if (*(first_number_digits + first_index) ==
                    *(second_number_digits + first_index))
            {
                if (first_index == first_digit_count)
                {
                    first_index = first_digit_count - ONE;
                    second_index = second_digit_count - ONE;
                    larger_number_flag = ZERO;
                    result_loop_limit = first_digit_count - ONE;
                }
            }

            first_index++;
        }
    }
    /* Case 2: First number has more digits */
    else if (first_digit_count > second_digit_count)
    {
        first_index = first_digit_count - ONE;
        second_index = second_digit_count - ONE;
        larger_number_flag = ZERO;
        result_loop_limit = first_digit_count - ONE;
    }
    /* Case 3: Second number has more digits */
    else if (second_digit_count > first_digit_count)
    {
        first_index = second_digit_count - ONE;
        second_index = first_digit_count - ONE;
        larger_number_flag = ONE;
        result_loop_limit = second_digit_count - ONE;
    }

    /* Temporary buffer to store numeric subtraction result */
    int *temp_digit_buffer = (int *)calloc(FIFTY, sizeof(int));
    if (temp_digit_buffer == NULL)
    {
        return; /* Memory allocation failed */
    }

    /* Perform digit-by-digit subtraction */
    while (first_index >= ZERO)
    {
        switch (larger_number_flag)
        {
        /* Subtract: first number - second number */
        case ZERO:
            if (*(first_number_digits + first_index) >=
                    *(second_number_digits + second_index))
            {
                *(temp_digit_buffer + result_index) =
                    *(first_number_digits + first_index) -
                    *(second_number_digits + second_index);
            }
            else
            {
                /* Borrow handling */
                *(first_number_digits + first_index) += FIFTY;
                *(first_number_digits + (first_index - ONE)) -= ONE;
                *(temp_digit_buffer + result_index) =
                    *(first_number_digits + first_index) -
                    *(second_number_digits + second_index);
            }
            break;

        /* Subtract: second number - first number */
        case ONE:
            if (*(second_number_digits + first_index) >=
                    *(first_number_digits + second_index))
            {
                *(temp_digit_buffer + result_index) =
                    *(second_number_digits + first_index) -
                    *(first_number_digits + second_index);
            }
            else
            {
                /* Borrow handling */
                *(second_number_digits + first_index) += FIFTY;
                *(second_number_digits + (first_index - ONE)) -= ONE;
                *(temp_digit_buffer + result_index) =
                    *(second_number_digits + first_index) -
                    *(first_number_digits + second_index);
            }
            break;

        default:
            printf("invalid\n");
        }

        /* Move to next digit */
        first_index--;
        second_index--;
        result_index--;

        /* Copy remaining digits when smaller number is exhausted */
        switch (larger_number_flag)
        {
        case ZERO:
            while (second_index < ZERO && first_index >= ZERO)
            {
                *(temp_digit_buffer + result_index) =
                    *(first_number_digits + first_index);
                first_index--;
                result_index--;
            }
            break;

        case ONE:
            while (second_index < ZERO && first_index >= ZERO)
            {
                *(temp_digit_buffer + result_index) =
                    *(second_number_digits + first_index);
                first_index--;
                result_index--;
            }
            break;
        }
    }

    /* Convert numeric digits to ASCII characters */
    for (first_index = NINE; first_index >= ZERO; first_index--)
    {
        *(result_buffer + first_index) =
            *(temp_digit_buffer + first_index) + '0';

        result_loop_limit--;
        if (result_loop_limit < ZERO)
        {
            break;
        }
    }

    /* Free temporary buffer */
    free(temp_digit_buffer);

    /* Remove leading zeros from result */
    while (result_buffer[ZERO] == ZERO || result_buffer[ZERO] == '0')
    {
        for (first_index = ZERO; first_index < TEN; first_index++)
        {
            *(result_buffer + first_index) =
                *(result_buffer + (first_index + ONE));
        }
    }
    printf("sub :%s\n",result_buffer);
}
/******************************************************************************
 * @brief   Performs division of two multi-digit numbers represented as
 *          digit arrays.
 *
 * @details
 * This function computes the quotient and remainder of two large numbers
 * where each number is represented as an array of individual digits.
 *
 * The division is performed using an iterative approach:
 * - Validates that the dividend is greater than or equal to the divisor.
 * - Uses an incremental counter to generate candidate quotient values.
 * - Multiplies the divisor with the counter value.
 * - Compares the result with the dividend to determine the correct quotient.
 * - Computes the remainder using subtraction once the quotient is finalized.
 *
 * The final results (quotient and/or remainder) are converted into ASCII
 * representation and stored in the provided result buffer.
 *
 * @param[in]  dividend_digits        Pointer to the digit array of the dividend.
 * @param[in]  divisor_digits         Pointer to the digit array of the divisor.
 * @param[out] result_buffer          Pointer to the character buffer where
 *                                   the result will be stored as a string.
 * @param[in]  dividend_digit_count   Number of digits in the dividend.
 * @param[in]  divisor_digit_count    Number of digits in the divisor.
 *
 * @return
 *          None
 *
 * @note
 * - Supports multi-digit arithmetic based on allocated buffer sizes.
 * - Uses dynamic memory for intermediate calculations.
 * - Relies on counter-based multiplication for quotient determination.
 * - The result is stored as a null-terminated ASCII string.
 * - The caller must ensure sufficient memory is allocated for result_buffer.
 *
 * @warning
 * - Division by zero must be handled externally before calling this function.
 *
 * @dependencies
 * - subtract_digit_arrays()
 * - multiply_digit_arrays()
 * - convert_string_digits_to_int_array()
 * - multi_digit_50_counter()
 *
 ******************************************************************************/
void divide_digit_arrays(int *dividend_digits,
                         int *divisor_digits,
                         char *result_buffer,
                         int dividend_digit_count,
                         int divisor_digit_count)
{
    /* Index variables for quotient and dividend traversal */
    int quotient_index = ZERO;
    int dividend_index = ZERO;

    /* Temporary index and comparison helpers */
    int temp_index = ZERO;
    int compare_index = ZERO;
    int temp_value = ZERO;

    /* Digit comparison values */
    int compare_a = ZERO;
    int compare_b = ZERO;

    /* Flag to track equal digits during comparison */
    int equal_flag = ZERO;

    /* Loop control variables */
    int loop_limit = FIVE;
    int counter_start = ONE;

    int outer_loop = ZERO;
    int inner_loop = ZERO;
    int counter_step = ONE;

    /* Static counter to track number of digits in multiplier */
    static int active_digit_count = ZERO;

    /* Various helper indices and counters */
    int digit_count = ZERO;
    int index_a = ZERO;
    int index_b = ZERO;
    int counter_value = ONE;
    int buffer_index = ZERO;
    int result_length = ZERO;
    int temp_resLength = ZERO;
    int counter_digit_count = ONE;
    int Exist_flag = ZERO;
    int equal_dig_identify = ZERO;
    int rem_identify = ZERO;
    int dig_cnt = ZERO;
    int num_check = ZERO;
    int string_len = ZERO;
    /* Pointer for dynamic counter digits */
    int *counter_digits = NULL;

    /* Temporary buffer to hold intermediate numeric values */
    int *temp_digit_array = (int *)calloc(FIFTY, sizeof(int));

    /* Validate dividend >= divisor when digit counts are equal */
    if (dividend_digit_count == divisor_digit_count)
    {
        /*validate divisor and dividend are same*/

        for (index_a = ZERO; index_a < dividend_digit_count; index_a++)
        {
            if (*(divisor_digits + index_a) ==
                    *(dividend_digits + index_a))
            {
                dig_cnt++;

            }


            if (*(divisor_digits + index_a) <
                    *(dividend_digits + index_a))
            {
                break;
            }

            if (*(divisor_digits + index_a) >
                    *(dividend_digits + index_a))
            {
                printf("Invalid: ");
                return;
            }
        }
        if (dig_cnt == dividend_digit_count)
        {

            printf("\n");
            printf("Quitient %d: \n",1);
            printf("Remainder %d: \n",0 );
            return;
        }

    }

    /* Main division processing loop */
    while (outer_loop < TWO)
    {
        /* If result length reaches dividend length */
        if (temp_resLength >= dividend_digit_count)
        {
            /* Compare quotient digits with dividend digits */
            while ((*(result_buffer + quotient_index) - FORTY_EIGHT) >=
                    (*(dividend_digits + dividend_index)) ||
                    temp_resLength > dividend_digit_count||num_check!=dividend_digit_count)
            {
                if((quotient_index||dividend_index)==dividend_digit_count)
                {
                    break;
                }
                /* If quotient exceeds dividend, subtract divisor */
                if ((*(result_buffer + quotient_index) - FORTY_EIGHT) >
                        (*(dividend_digits + dividend_index)) ||
                        temp_resLength > dividend_digit_count||num_check!=dividend_digit_count)
                {
                    memset(result_buffer, '\0', ELEVEN * sizeof(char));

                    subtract_digit_arrays(temp_digit_array,
                                          divisor_digits,
                                          result_buffer,
                                          temp_resLength,
                                          divisor_digit_count);

                    /* Reset temporary buffer */
                    memset(temp_digit_array, ZERO, FIFTY * sizeof(int));

                    convert_string_digits_to_int_array(result_buffer,
                                                       temp_digit_array);
                    temp_resLength = ZERO;
                    result_length = ZERO;
                    outer_loop = ZERO;
                    rem_identify = ONE;                                      // couter digit update;
                    // rem_identification should be mark
                    string_len = string_length(result_buffer);
                    break;
                }

                /* Exit if result digit is zero */
                if (*(result_buffer + quotient_index) == ZERO)
                {
                    break;
                }
                if(temp_resLength <= ZERO)
                {
                    break;
                }
                temp_resLength--;
                quotient_index++;
                dividend_index++;
                // condition apply length <than 0 exist(solved)
            }

            /* Reset indices for remainder calculation */
            quotient_index = ZERO;
            dividend_index = ZERO;
            memset(result_buffer, '\0', FIFTY_ONE * sizeof(char));

            /* Calculate remainder */
            if(rem_identify==ONE)
            {
                subtract_digit_arrays(dividend_digits,
                                      temp_digit_array,
                                      result_buffer,
                                      dividend_digit_count,
                                      string_len);
                /* Decrement final quotient digit */
                *(counter_digits + (counter_digit_count - ONE)) =
                    (*(counter_digits + (counter_digit_count - ONE)) - ONE);
            }



            /* Print quotient */

            printf("\n");
            printf("Quitient: ",counter_digits);
            for (index_a = ZERO; index_a < counter_digit_count; index_a++)
            {
                printf("%d", counter_digits[index_a]);
            }
            printf("\n");
            /* Print remainder */
            if(rem_identify==ONE)
            {
                printf("Remainder: %s\n", result_buffer);
                break;
            }
            else
            {
                printf("Remainder: %d\n", 0);
            }
            return 0;
        }
        else
        {
            /* Multiply divisor by current counter */
            multiply_digit_arrays(divisor_digits,
                                  &counter_value,
                                  result_buffer,
                                  divisor_digit_count,
                                  counter_digit_count);

            /* Extract leading digits for comparison */
            compare_a = (int)(*(result_buffer + buffer_index) - FORTY_EIGHT);
            compare_b = (int)*(dividend_digits + temp_index);
        }

        /* Compare multiplied result with dividend */
        while (((*(result_buffer + buffer_index) - FORTY_EIGHT) <=
                *(dividend_digits + temp_index))||(dividend_digit_count>=divisor_digit_count) &&
                (*(result_buffer + buffer_index) != '\0'))
        {
            /* Increment counter until result exceeds dividend */
            for (counter_value = counter_step;
                    compare_a < compare_b||dividend_digit_count>=divisor_digit_count;
                    counter_value++)
            {
                /* Initialize multi-digit counter */
                if (counter_value == ONE)
                {
                    /*special counter upto 50 digit numbers */
                    multi_digit_50_counter(&active_digit_count);
                }

                counter_digits =
                    multi_digit_50_counter(&active_digit_count);

                counter_digit_count = active_digit_count;

                if (counter_digits == NULL)
                {

                    return;
                }

                /* Multiply divisor with updated counter */
                multiply_digit_arrays(divisor_digits,
                                      counter_digits,
                                      result_buffer,
                                      divisor_digit_count,
                                      counter_digit_count);

                /* Measure result length */
                while (*(result_buffer + digit_count) != '\0')
                {
                    result_length++;
                    digit_count++;
                }

                digit_count = ZERO;

                /* Result exceeds dividend */
                // printf("result_buffer + buffer_index) %d\n",(*(result_buffer + buffer_index) - FORTY_EIGHT));
                if ((*(result_buffer + buffer_index) - FORTY_EIGHT) >
                        *(dividend_digits + temp_index) &&
                        result_length == dividend_digit_count)
                {
                    dividend_index = buffer_index;
                    quotient_index = temp_index;
                    temp_index = dividend_digit_count;
                    Exist_flag=1;
                    temp_resLength = result_length;
                    break;
                }

                /* Result length larger than dividend */
                if (result_length > dividend_digit_count)
                {
                    dividend_index = buffer_index;
                    quotient_index = temp_index;
                    temp_index = dividend_digit_count;
                    Exist_flag=1;
                    temp_resLength = result_length;
                    break;
                }

                /* Handle equal-length comparison */
                if (result_length == dividend_digit_count)
                {
                    compare_a = (*(result_buffer + buffer_index) - FORTY_EIGHT);
                    compare_b = *(dividend_digits + temp_index);

                    if (compare_a == compare_b)
                    {
                        loop_limit = compare_a;
                        counter_start = compare_b;
                    }
                }

                /* Full digit-by-digit comparison */
                if (result_length == dividend_digit_count &&
                        loop_limit == counter_start)
                {
                    for (inner_loop = ZERO;
                            inner_loop < result_length;
                            inner_loop++)
                    {
                        if ((*(result_buffer + inner_loop) - FORTY_EIGHT) >
                                (*(dividend_digits + inner_loop)))
                        {
                            temp_index = dividend_digit_count;
                            Exist_flag=1;
                            break;
                        }

                        if ((*(result_buffer + inner_loop) - FORTY_EIGHT) ==
                                *(dividend_digits + inner_loop))
                        {
                            buffer_index++;
                            temp_index++;
                            compare_a =
                                (*(result_buffer + buffer_index) - FORTY_EIGHT);
                            compare_b =
                                *(dividend_digits + temp_index);
                            counter_step = ONE;
                            equal_dig_identify++;
                            if(dividend_digit_count==equal_dig_identify)
                            {
                                Exist_flag=ONE;
                                equal_dig_identify=0;
                                //temp_resLength=0;
                                break;
                            }
                        }
                        if ((*(result_buffer + inner_loop) - FORTY_EIGHT) <
                                (*(dividend_digits + inner_loop)))
                        {

                            break;
                        }
                    }
                }
                temp_resLength = result_length;
                result_length = ZERO;
                buffer_index = ZERO;
                temp_index = ZERO;
                num_check=equal_dig_identify;
                equal_dig_identify =ZERO;

                // res - didv
                /* Exit if dividend fully processed */
                if (Exist_flag == ONE)
                {
                    temp_index = dividend_digit_count;

                    break;

                }
            }

            /* Exit if dividend fully processed */
            if (temp_index == dividend_digit_count)
            {
                //temp_resLength = result_length;
                //outer_loop = TWO;
                break;

            }
        }

        outer_loop++;

        /* Convert result string back to digit array */
        convert_string_digits_to_int_array(result_buffer,
                                           temp_digit_array);
       // for(int o=0; o<dividend_digit_count; o++)
       // {
      //      printf("tp :%d",temp_digit_array[o]);
      //  }
    }

    /* Free allocated memory */
    free(temp_digit_array);
}
/* ================= MAIN ================= */
/******************************************************************************
 * @brief   Entry point for multi-digit arithmetic calculator application.
 *
 * @details
 * This function initializes required buffers and variables, reads input
 * numbers and operation type, and performs the corresponding arithmetic
 * operation based on user input.
 *
 * The supported operations include:
 * - Addition        ('A')
 * - Subtraction     ('S')
 * - Multiplication  ('M')
 * - Division        ('D')
 *
 * The input numbers are read as strings, converted into digit arrays,
 * and processed using dedicated arithmetic functions. The result is
 * stored as an ASCII string in the result buffer.
 *
 * @return
 *          int  -> Program execution status
 *
 * @note
 * - Supports multi-digit arithmetic (e.g., up to 50 digits).
 * - Uses fixed-size buffers for input and result storage.
 * - The function executes a single operation and exits.
 * - 'E' operation type is used to indicate an error or exit condition.
 * - Debug print statements (printf) are used for interaction/output.
 *
 * @dependencies
 * - read_digit_arrays()
 * - add_digit_arrays()
 * - subtract_digit_arrays()
 * - multiply_digit_arrays()
 * - divide_digit_arrays()
 *
 ******************************************************************************/
int main()
{
    int count_a[FIFTY]= {ZERO},count_b[FIFTY]= {ZERO};
    int count_len_a=ZERO,count_len_b=ZERO;
    char type;
    char result_buffer[FIFTY_ONE]= {ZERO};
    printf("Calc.......");
    printf("\n");
    read_digit_arrays(count_a,count_b,&count_len_a,&count_len_b,&type);
    printf("%c\n",type);
  //  printf("%d size\n",sizeof(long long));
    while(1)
    {
        switch(type)
        {
        case 'M' :
            //Mux
            multiply_digit_arrays(count_a,
                                  count_b,
                                  result_buffer,
                                  count_len_a,
                                  count_len_b);
            // printf("result_buffer :%s",result_buffer);

            break;
        case 'A' :
            //Add
            add_digit_arrays(count_a,
                             count_b,
                             result_buffer,
                             count_len_a,
                             count_len_b);
            break;
        case 'S' :
            //sub
            subtract_digit_arrays(count_a,
                                  count_b,
                                  result_buffer,
                                  count_len_a,
                                  count_len_b);
            break;
        case 'D' :
            //DIV
            divide_digit_arrays(count_a,
                                count_b,
                                result_buffer,
                                count_len_a,
                                count_len_b);

            break;
        case 'E' :
            printf("QUIT");
            break;
        }
        break;
    }



}
