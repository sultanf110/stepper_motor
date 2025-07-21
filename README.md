# motorctrl

A Python wrapper for controlling stepper motors using a C function (`MotorCtrl`) built on the `wiringPi` GPIO library.

This package allows you to control up to three motors on a Raspberry Pi using Python, while executing high-performance GPIO logic written in C.

---

## 🚀 Features

- Simple Python interface: `call_motor_ctrl(motor, steps, latency, direction)`
- Underlying C code compiled and linked to `wiringPi`
- Supports up to 3 motors with predefined GPIO pins
- Packaged and installable via `pip install .`

---

## 🔧 Installation

### 1. Prerequisites

- Raspberry Pi with GPIO headers
- [`wiringPi`](http://wiringpi.com) installed and available (may require `sudo apt install wiringpi` or an alternative if it's deprecated — consider [WiringPi reimplementations](https://github.com/WiringPi/WiringPi))
- GCC compiler (`gcc`)
- Python 3.7+

### 2. Install from source

Clone this repo and run:

```bash
pip install .
```

This will automatically compile the C source (`motorctrl.c`) into a shared library (`libmotorctrl.so`), and install the Python wrapper.

---

## 🧪 Usage

```python
from motorctrl import call_motor_ctrl

# call_motor_ctrl(motor_number, steps, latency_ms, direction)
call_motor_ctrl(1, 200, 100, 0)  # Motor 1, 200 steps, 100ms latency, forward
```

### Arguments

| Name       | Type | Description                             |
|------------|------|-----------------------------------------|
| `motor`    | int  | Motor number (1, 2, or 3)               |
| `steps`    | int  | Number of motor steps                   |
| `latency`  | int  | Delay between half-steps (milliseconds) |
| `direction`| int  | 0 = forward, 1 = backward               |

---

## 📁 Project Structure

```
motorctrl/
├── motorctrl/
│   ├── __init__.py
│   ├── wrapper.py          # Python wrapper around libmotorctrl.so
│   ├── motorctrl.c         # C source code with MotorCtrl()
│   └── libmotorctrl.so     # Built shared object (generated)
├── setup.py
├── README.md
└── MANIFEST.in
```

---

## 🛠 Development

To manually rebuild the shared library:

```bash
gcc -shared -fPIC motorctrl/motorctrl.c -o motorctrl/libmotorctrl.so -lwiringPi
```

To reinstall:

```bash
pip install --force-reinstall .
```

---

## 📜 License

MIT License — use freely, at your own risk. GPIOs are fun, but also sharp.

---

## 🙋 FAQ

**Q:** What if I get `undefined symbol: digitalWrite`?  
**A:** Make sure `libmotorctrl.so` is compiled with `-lwiringPi`.

**Q:** Can I use this outside a Raspberry Pi?  
**A:** Only if you emulate or stub out `wiringPi`. It's built specifically for RPi GPIO control.

---
