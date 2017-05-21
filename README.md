# tranker
Yet another music tracker playground project

* Tracker style music editor featuring multi-level 8 steps sequencers. The design should allow 2^n steps where n can be any number, but the user interface should be perfectly optimized for n=3.
* Event driven. Every state can be reproduced by replaying the history of events. All events are logged.
* Undoing will keep the event list but move the current pointer to previous. If making a new change when the pointer is not on top, an event branch will be created. This way you can always step back and forth in time, eliminating the need for saving progess snapshots.

## Sequencer Events

There are different types of sequences.

### Note Sequencer

Made for building sequences of melodic instruments. Based on western note scale, but every step is transposible in a number steps between each semitone. Notes are entered tracker style. C2 is corresponds to the middle C key of an 88 key piano. Here C is the note and 2 is the octave. Lower number is lower octave.

Events:

* SetNoteOnAt(StepNumber, Note, Octave, Velocity)
* SetNoteOffAt(StepNumber)
* ClearAt(StepNumber)

### Drum Sequencer

TODO

### Meta Sequencer

Like the Note and Drum sequencers, the Meta sequencer keep 8 steps. But Instead of notes each step refers to another sequencer of any type.

Events:

* SetSequenceAt(StepNumber, Sequence, Transpose)


