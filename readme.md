## This repo is discontinued

This repo was discontinued and I discourage you to use if there's a better fork.

This repo can be deleted anytime so if you like it, fork it and polish it before it's gone.

# Usb Reset
A simple program to reset usb devices in linux.

## Usage Tips

**IMPORTANT NOTE:** If you downloaded the binary you can **skip to item 3!**

0. Clone this repository

1. Compile the program

> cc usbreset.c -o usbreset

2. Make the binary executable (if you need [^1])

> chmod +x usbreset

[^1]: You only need it if after compilation the binary has no **x** permission for some reason.

3. Get the IDs via **lsusb** on terminal:

> lsusb

The output will be like:

```
Bus 002 Device 003: ID xxxx:xxxx USB OPTICAL MOUSE
Bus 001 Device 002: ID xxxx:xxxx USB Keyboard
Bus 001 Device 003: ID xxxx:xxxx USB Audio Interface
```

4. Run as sudo (change the **[BUS]** and **[DEVICE]** for the values):

> sudo ./usbreset /dev/bus/usb/[BUS]/[DEVICE]

**Example:** If I want to reset my USB Audio Interface (based on the lsusb used before)

BUS is **001**, Device is **002**

> sudo ./usbreset /dev/bus/usb/001/003

---

## FAQ

Q: I'm getting "Error opening output file"

A: Run as root or with admin privileges.
