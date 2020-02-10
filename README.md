# Neuron
 A simple C++ neuron library (designed for Arduinos)

## Usage
Add the Neuron.zip file from the releases page to your Arduino project.

```cpp
Neuron* n = new Neuron(1, 0.01, 0.2, 0.2);

bool isOn = n->Receive(0.1, 0.02);
```