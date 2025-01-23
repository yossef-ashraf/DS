<?php

use APP\Stack\Stack;

require 'vendor/autoload.php';

$stack = new Stack();
$stack->push(10);
$stack->push(20);
$stack->push(30);
echo "Top element: " . $stack->top() . "\n"; // Outputs 30
echo "<br>";
echo "Popped element: " . $stack->pop() . "\n"; // Outputs 30
echo "<br>";
echo "Top element after pop: " . $stack->top() . "\n"; // Outputs 20
echo "<br>";
echo "Is stack empty? " . ($stack->isEmpty() ? "Yes" : "No") . "\n"; // Outputs No
echo "<br><br><br>";

