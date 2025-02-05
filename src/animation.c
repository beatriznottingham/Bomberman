#include "animation.h"

/* Function to return a Rectangle type with the coordinates of the frame in the sheet
 to pass as an argument in DrawTexturePro*/
Rectangle SpriteAnimationFrame(Animation *self, int numFramesPerLine, float objHeight, float objWidth)
{
    /*coordenates of the specific image of the spritesheet
    the operation below gives us the proportion of the image relative to the sprite
    multiplied by the size of each image*/
    int x = (self->curr % numFramesPerLine) * objWidth;
    int y = (self->curr / numFramesPerLine) * objHeight;
    Rectangle returnRec = 
    {
        .x = (float)x,
        .y = (float)y,
        .width = objWidth,
        .height = objHeight
    };
    return returnRec;
}

/*First, the accumulatedTime variable was created within the function, but,
because of the needed to be a static float variable in order to keep track of
time across multiple calls, when this function was called more times, each function
would share the same static float, causing trouble with multiple animations

Therefore, the accumulatedTime will be declared as a global variable and passed as an argument
individually to each animation*/

// Updating the frame in the sheet that will be draw, creating an animation
void SpriteAnimationUpdate(Animation *self, float *accumulatedTime)
{
    // Accumulate time between frames with the float variable

    // Add time elapsed from last frame
    *accumulatedTime += GetFrameTime(); // GetFrameTime() returns time since last frame

    // Check if accumulated time is enough to move to the next frame
    while (*accumulatedTime >= self->frameTimer)
    {
        self->curr++;  // Move to the next frame
        *accumulatedTime -= self->frameTimer;  // Subtract frame time from accumulated time
    
        // Check if the animation should stop or loop
        if (self->curr > self->last)
        {
            switch (self->type)
            {
                case CONTINUOUS:
                    self->curr = self->first; // Loop back to the first frame  
                    break;
                case ONESHOT:
                    self->curr = self->last;  // Stop at the last frame
                    break;
            }
        }
    }
}

//function to repeat an Oneshot sprite animation when needed
void SpriteAnimationShouldRepeat(Animation *self)
{
    //Repeating a Oneshot animation if its continuously being called
    if(self->curr == self->last) self->curr = self->first;
}



