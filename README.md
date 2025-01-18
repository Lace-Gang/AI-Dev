# About The Project

This project creates two simple types of cellular AI: Elementary Cellular Automata, and Conway's Game of Life.

Scene types can be changed in Main.cpp by changing which of these scene lines is uncommented. <br/>
<img width="506" alt="image" src="https://github.com/user-attachments/assets/64f0fa05-fae2-4eca-9c77-22c1afbb50c7" />

## Example Scene
ExampleScene is a test to ensure that the display screen is working properly. When used, this scene should display pixels of random colors at random possitions on the screen. These pixels will change every frame.<br/>
<img width="613" alt="image" src="https://github.com/user-attachments/assets/371ec33d-b517-43e6-ba92-9941ba5334bb" />


## Elementary Cellural Automata
The Elementary Cellular Automata is a one dimensional cellular automata that will display a static image generated using the given integer "rule" as a basis. Each pixel is calculated by taking the values of the 
pixel directly above it, and the two that border that pixel on it's own row. These pixels are compaired to the bit pattern of the given rule, and the result determines if the pixel is "on" or "off". This is a 
determinalistic AI in that the same rule will always result in the same static image.

The rule can be changed by changing the int rule variable in the Update function in CAScene.cpp. <br/>
<img width="377" alt="image" src="https://github.com/user-attachments/assets/ccdd6dd5-dca7-498b-a76f-d14e80bf0a90" />

The below is an example of one pottential output.<br/>
<img width="608" alt="image" src="https://github.com/user-attachments/assets/11564942-99b7-4141-8719-25e50045d373" />


 ## Conway's Game of Life
 Conway's Game of Life is a generational two dimensional cellular automata where each pixel is calculated based on the state of the 8 immediately surrounding cells in the previous generation using 3 rules.
 
 Rules:<br/>
 &nbsp; &nbsp; &nbsp; &nbsp;1.) If there are less than two living cells surrounding a living cell, it dies as if by underpopulation.<br/>
 &nbsp; &nbsp; &nbsp; &nbsp;2.) If there are more than three living cells surrounding a living cell, it does as if by overpopulation.<br/>
 &nbsp; &nbsp; &nbsp; &nbsp;3.) If there are exactly three living cells surrounding a dead cell, that cell is revived as if by repopulation.<br/>
 &nbsp; &nbsp; &nbsp; &nbsp;4.) A living cell surrounded by two or three living cells lives on to the next generation. This is sometimes listed as a rule, <br/>
 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;but not always, as it is the natural implication of rules two and three.<br/>
          
Conway's Game of Life is determinalistic in that the same input array of cells will always result in the same ouput behavior. However, this does not occur in this project as it is because the input is randomized.

When running the project, use the spacebar to repopulate the scene. This will be necessary at the start, and when the AI falls into a state of unchanging order.

Results will vary, but will likely look something like this:<br/>
<img width="614" alt="image" src="https://github.com/user-attachments/assets/840b6a88-6139-4073-9f9f-2d7f06285dc9" /> <br/>
<img width="618" alt="image" src="https://github.com/user-attachments/assets/66087bdd-0a95-46ff-b405-795614773c02" />

