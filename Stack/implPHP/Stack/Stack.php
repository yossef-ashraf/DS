<?php

namespace APP\Stack;
use RuntimeException;

class Stack {
    private $stack;
    private $size;

    public function __construct() {
        $this->stack = array();
        $this->size = 0;
    }

    // Add an element to the top of the stack
    public function push($element) {
        $this->stack[$this->size++] = $element;
    }

    // Remove and return the top element of the stack
    public function pop() {
        if ($this->isEmpty()) {
            throw new RuntimeException("Stack is empty.");
        }
        return $this->stack[--$this->size];
    }

    // Return the top element of the stack without removing it
    public function top() {
        if ($this->isEmpty()) {
            throw new RuntimeException("Stack is empty.");
        }
        return $this->stack[$this->size - 1];
    }

    // Check if the stack is empty
    public function isEmpty() {
        return $this->size === 0;
    }

    // Get the current size of the stack
    public function getSize() {
        return $this->size;
    }

    // Remove all elements from the stack
    public function clear() {
        $this->stack = array();
        $this->size = 0;
    }

    // Return a string representation of the stack
    public function __toString() {
        return implode(', ', $this->stack);
    }

    // Return the stack as an array
    public function toArray() {
        return $this->stack;
    }

    // Return the reversed stack as an array
    public function toArrayReversed() {
        return array_reverse($this->stack);
    }

}
// chatgpt :
// Explanation of operations:
// push($element):

// Adds the element $element to the end of the array $stack.
// The $size pointer is incremented by 1.
// pop():

// First it checks if the stack is empty. If it is empty, throw an exception.
// It decrements the $size index by 1 and returns the element at this index.
// top():

// First it checks if the stack is empty. If it is empty, throw an exception.
// Returns the element at index $size - 1 without removing it from the stack.
// isEmpty():

// Checks if the $size pointer is 0.
// getSize():

// Returns the current value of the $size pointer.
// Stack Uses:
// Evaluating arithmetic expressions:
// Such as converting Infix expressions to Postfix or evaluating Postfix expressions.
// Managing recurring calls:
// Such as simulating recursive function calls using a call stack.
// Check the balance of the brackets:
// Such as checking the balance of the parentheses in a programming or mathematical expression.