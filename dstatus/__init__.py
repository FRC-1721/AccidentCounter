import sys

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QLabel, QMainWindow, QPushButton


class Window(QMainWindow):
    def __init__(self):
        super().__init__()

        # setting geometry
        self.setGeometry(100, 100, 600, 400)

        # calling method
        self.UiComponents()

        # showing all the widgets
        self.show()

    # method for widgets
    def UiComponents(self):
        # creating label
        label = QLabel("I CAN DO IT", self)

        button = QPushButton("Quit", self)

        # setting geometry of button
        button.setGeometry(200, 150, 100, 40)

        # changing color of button
        button.setStyleSheet("background-color : yellow")

        # adding action to a button
        button.clicked.connect(self.exitCleanly)

        label.setAlignment(Qt.AlignHCenter)

        # adding border to label
        label.setStyleSheet("border : 2px solid black")

        # opening window in maximized size
        self.showMaximized()

    def exitCleanly(self):
        # printing pressed
        quit()


# create pyqt5 app
App = QApplication(sys.argv)

# create the instance of our Window
window = Window()

# start the app
sys.exit(App.exec())
