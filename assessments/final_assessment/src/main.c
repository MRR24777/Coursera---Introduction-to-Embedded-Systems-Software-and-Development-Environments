 
 /******************************************************************************
 * Copyright (C) 2025 by Misael Reyna
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain the copyright found in 
 * the LICENSE file.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 *
 *****************************************************************************/

/**
 * @file main.c 
 * @brief This file is the main file for the final assessment of course1. It serves as the entry point
 *        for the program and calls the `course1()` function when the `COURSE1` macro is defined.
 *
 * This program demonstrates the use of various modules, including memory management, statistics, and
 * data manipulation, as part of the final assessment for the course. The `course1()` function is
 * conditionally compiled and executed based on the presence of the `COURSE1` macro.
 *
 * @author Misael Reyna
 * @date February 25th, 2021
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"
#include "stats.h"
#include "data.h"


int main(){
    #ifdef COURSE1
        printf("calling course1()\n");
        course1();  
        return 0;
    #endif

    return 0;
}
