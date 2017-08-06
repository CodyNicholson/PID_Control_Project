# PID Control Project

Control is how we use the steering, throttle, and brakes to move a car where we want it to go. When we turn through an intersection we use our intuition and experience to determine how hard to steer, when to accelerate, and whether to step on the brakes. Control algorithms are often called "controllers" and one of the most common and fundamental controllers is the PID Controller.

In this project I created a PID controller to handle the self-driving car's three actuators: steering, throttle, and brake. This controller corrects the car's driving when it makes mistakes - like overshooting turns.

### Reflection Questions

##### Describe the effect each of the P, I, D components had in your implementation

**P** component stands for *proportional*. Using the **P** component, the car will always steer proportional to the car's distance from the center of the lane (denoted **cte**).

**I** stands for *integral*. The **I** component helps offset the bias in the CTE that can be caused by steering drift when the car turns.

**D** stands for *differential*. Sometimes the **P** component overshoots the **cte** (center of the line), so to offset this issue we use the differential component.

*Student describes the effect of the P, I, D component of the PID algorithm in their implementation. Is it what you expected?*

##### Describe how the final hyperparameters were chosen

I started by tuning my hyperparameters manually to get myself started. I wanted to start moving in the right direction before I let Twiddle handle the rest of the parameter optimization. After the car was able to get around the track I switched to Twiddle for my optimization. I let it drive for a long time to best tune the parameters to the optimal values.

*Student discusses how they chose the final hyperparameters (P, I, D coefficients). This could be have been done through manual tuning, twiddle, SGD, or something else, or a combination!*

---

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)
