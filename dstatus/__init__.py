# importing libraries
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
import sys


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

        button = QPushButton("CLICK", self)
  
        # setting geometry of button
        button.setGeometry(200, 150, 100, 40)
  
        # changing color of button
        button.setStyleSheet("background-color : yellow")
  
        # adding action to a button
        button.clicked.connect(self.clickme)

        label.setAlignment(Qt.AlignHCenter)

        # adding border to label
        label.setStyleSheet("border : 2px solid black")

        # opening window in maximized size
        self.showMaximized()
        
    def clickme(self):
        # printing pressed
        quit()


# create pyqt5 app
App = QApplication(sys.argv)

# create the instance of our Window
window = Window()

# start the app
sys.exit(App.exec())
