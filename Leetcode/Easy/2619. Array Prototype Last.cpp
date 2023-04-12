//! Using at() and ??

/*
Nullish coalescing operator (??)

The nullish coalescing (??) operator is a logical operator that returns its right-hand side operand when its left-hand side operand is null or undefined, and otherwise returns its left-hand side operand.

The at() method takes an integer value and returns the item at that index, allowing for positive and negative integers. Negative integers count back from the last item in the array.

For invalid indexes it will return undefined
*/

Array.prototype.last = function()
{
    return this.at(-1) ?? -1;
};

//! Using Array.prototype.length

Array.prototype.last = function()
{
    if (this.length == 0)
    {
        return -1;
    }
    else
    {
        return this[this.length - 1];
    }
};

/*
Inside the Array.prototype.last function body, you have access to the "this" keyword. "this" is equal to the contents of the array in this case.

You can access elements in the array via this[0], this[1], etc. You can also access properties and method like this.length, this.forEach, etc.
*/

/*
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */