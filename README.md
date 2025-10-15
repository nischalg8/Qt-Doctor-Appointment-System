# DAS Project (Doctor Appointment System)

## Description

This project implements a **Doctor Appointment System (DAS)** using **C++ and Qt**.  
It provides a comprehensive solution for managing medical appointments with a local SQLite database storing doctor information and appointment records.

## Features

- **Appointment Management**
  - Schedule new appointments with available doctors
  - Reschedule existing appointments
  - Cancel appointments
- **Doctor Database**
  - Store and manage doctor information locally using SQLite
  - View doctor profiles and availability
- **User-friendly Interface**
  - Intuitive Qt-based graphical interface
  - Easy navigation and appointment handling
- **Cross-platform Support**
  - Compatible with Windows, Linux, and macOS

## Dependencies

- **Qt 5.x or Qt 6.x** (minimum Qt 5.0 required)

### Required Qt Modules

This project requires the following Qt modules:
- `Qt Core` - Core non-GUI functionality
- `Qt GUI` - GUI components
- `Qt Widgets` - Widget classes for UI
- `Qt SQL` - Database integration and SQL support

### Installation Notes

When installing Qt, ensure you select the following components:
- Desktop build tools for your platform
- Qt Charts (if data visualization is needed)
- Qt SQL drivers (PostgreSQL, MySQL, SQLite, etc., depending on your database)

## Setup and Installation

### Prerequisites

Install Qt from the official website:  
[https://www.qt.io/product/development-tools](https://www.qt.io/product/development-tools)

### Clone the Repository

```bash
git clone <repository_url>
cd DAS
```

### Build and Run

#### Option 1: Using Qt Creator (Recommended)

1. Launch **Qt Creator**
2. Click **File → Open File or Project**
3. Select the `DAS.pro` file from the cloned repository
4. Configure the project by choosing a compatible Qt kit
5. Click the **Build** button (hammer icon)
6. Click the **Run** button (green play icon) to start the application

#### Option 2: Using Command Line

```bash
# Generate Makefile
qmake DAS.pro

# Build the project
make

# Run the application
./DAS  # On Linux/macOS
# or
DAS.exe  # On Windows
```


## Troubleshooting

### Common Issues

- **Qt version mismatch**: Ensure your Qt installation matches the project requirements
- **Build errors**: Clean the build directory and rebuild (`Build → Clean All` in Qt Creator)
- **Missing modules**: Install required Qt modules through the Qt Maintenance Tool

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/YourFeature`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to the branch (`git push origin feature/YourFeature`)
5. Open a Pull Request

## Acknowledgments

- Qt Framework by The Qt Company
