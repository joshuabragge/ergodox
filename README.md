<!-- -*- mode: markdown; fill-column: 8192 -*- -->

SIMAK Layout
======================

This is a [Colemak][colemak] keyboard layout for the [ErgoDox Ez][ergodox-ez]. The layout is refined and tuned according to the demands of a SimCorp Anaylst working in a Windows environment. This layout is heavily influenced by the greatest keyboard firmware hacker of our time - [algernon][algernon] - and his thrilling [blog][blog].

[colemak]: https://en.wikipedia.org/wiki/Colemak
[ergodox-ez]: https://ergodox-ez.com/
[algernon]: https://github.com/algernon/ergodox-layout
[blog]: https://asylum.madhouse-project.org/blog/tags/ergodox/

## Table of Contents

* [Layouts](#layouts)
    - [Base layer](#base-layer)
    - [Movement layer](#movement-layer)
    - [Function layer](#function-layer)
    - [Numbers layer](#numbers-layer)
    - [Swap hand layer](#swap-hand-layer)
    - [LED states](#led-states)
* [Building](#building)
* [Changelog](https://github.com/joshuabragge/ergodox/blob/master/NEWS.md#readme)

# Layouts

## Base layer

[![Base layer](https://github.com/joshuabragge/ergodox/blob/master/images/base-layer.png)](http://www.keyboard-layout-editor.com/#/gists/dcfe02aa9e3c71d0d9e90ea362bb8889)

Features:
* Tapping the `ESC` key once yields `ESC`. Double-tapping the `ESC` key triggers `ALT`+`F4`,
* Dedicated screen lock button (ScrLCK) sends `LGUI`+`L`.
* Dedicated unlock screen button sends `CTRL`+`ALT`+`DEL`.
* When holding the `Tab`/**Arrow** key, the arrow layer activates while the key is held. Tapping the key produces the normal, `Tab` key. Double-tapping it toggles the **Arrow** layer on until a third tap - credit [algernon][algernon].
* Tapping the `:` key once yields `:`, tapping it twice yields `;` - credit [algernon][algernon].
* Tapping the `[{(`/`)}]` keys once yields `[` (or `{` when shifted), tapping them twice yields `(` - credit [algernon][algernon].
* The Shift, Alt, and Control modifiers are one-shot. When tapped, they are considered active for the next key press only. When double tapped, they toggle on, until a third, single tap sometime later. When held, they act as expected - credit [algernon][algernon].
* The Lead key allows typing in sequence of keys and then triggers some actions: 
    - `LEAD m e h` types `¯\_(ツ)_/¯`
    - `LEAD s` types "[SCD]"
    - `LEAD j b` types "joshua.bragge"
    - `LEAD d b` types "joshua.bragge.db"
    - `LEAD s v r` types "joshua.bragge.svr"
    - `LEAD f` types "from:"
    - `LEAD w m` maximizes the current window
    - `LEAD l` sends `LGUI` + `L` locking the computer
    - `LEAD u` sends `LCTRL` + `LALT` + `DEL` unlocking the computer (WIP)

## Movement layer

[![Movement layer](https://github.com/joshuabragge/ergodox/blob/master/images/movement-layer.png)](http://www.keyboard-layout-editor.com/#/gists/ac5c050a1ff346f686cf6384183e0891)

Features:
* VIM like arrow keys over home row.
* Easy access to home and end buttons (actually extremely useful for navigating).
* WASD mouse control.
* Symbols for easier access.

## Function layer

[![Function layer](https://github.com/joshuabragge/ergodox/blob/master/images/function-layer.png)](http://www.keyboard-layout-editor.com/#/gists/edb5d7dea96546757153b96de9133d32)

Places the `F` keys under the top-row numbers. This layer is accessable via a oneshot layer keys.

## Numbers layer

[![Numbers layer](https://github.com/joshuabragge/ergodox/blob/master/images/numbers-layer.png)](http://www.keyboard-layout-editor.com/#/gists/de6869b3f510813ffa8c433f077f66e7)

This places the symbols under the home row fingers and minimizes the need to hold `SHIFT`+NUM. This idea holds true for the number pad.

## Swap Hands

This layer swaps the layout between the two hands allowing one handed typing (in theory).

## LED states

For the layers, the following colours apply:

* When the **Base** layer is active, no LEDS are on.
* When the **Movement** layer is active, *green* will turn on.
* When the **Function** layer is active, *red* will turn on.
* When the **Number** layer is active, *blue* will turn on.
* when the **Qwerty** layer is active, *blue* and *red* will turn on.
* When the **Plover** layer is active, all the lights will turn on.
* When the **Swap Hand** layer is active, all the lights will turn on.

# Building

```
$ git clone https://github.com/qmk/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/joshuabragge/ergodox \
            layouts/community/ergodox/ergodox-jb
$ make ergodox_ez:ergodox-jb
