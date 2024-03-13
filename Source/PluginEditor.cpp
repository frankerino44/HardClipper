/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HardClipperAudioProcessorEditor::HardClipperAudioProcessorEditor (HardClipperAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    addAndMakeVisible(inputGainSlider);
    inputGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    inputGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 64, 32);
    inputGainSlider.setRange(1, 10, .1);
    inputGainSlider.setColour(juce::Slider::ColourIds::trackColourId, juce::Colours::whitesmoke);
    inputGainSlider.setDoubleClickReturnValue(true, 1.0);
    inputGainSlider.addListener(this);

    addAndMakeVisible(thresholdSlider);
    thresholdSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    thresholdSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 64, 32);
    thresholdSlider.setRange(0, 1, .01);
    thresholdSlider.setColour(juce::Slider::ColourIds::trackColourId, juce::Colours::whitesmoke);
    thresholdSlider.setDoubleClickReturnValue(true, 1.0);
    thresholdSlider.setValue(1.0);
    thresholdSlider.addListener(this);

    addAndMakeVisible(outputGainSlider);
    outputGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    outputGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 64, 32);
    outputGainSlider.setRange(1, 10, .1);
    outputGainSlider.setColour(juce::Slider::ColourIds::trackColourId, juce::Colours::whitesmoke);
    outputGainSlider.setDoubleClickReturnValue(true, 1.0);
    outputGainSlider.addListener(this);

    addAndMakeVisible(inputGainLabel);
    inputGainLabel.setText("Input", juce::dontSendNotification);
    inputGainLabel.attachToComponent(&inputGainSlider, false);
    inputGainLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(thresholdLabel);
    thresholdLabel.setText("Thresh", juce::dontSendNotification);
    thresholdLabel.attachToComponent(&thresholdSlider, false);
    thresholdLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(outputGainLabel);
    outputGainLabel.setText("Output", juce::dontSendNotification);
    outputGainLabel.attachToComponent(&outputGainSlider, false);
    outputGainLabel.setJustificationType(juce::Justification::centred);


    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (375, 325);
}

HardClipperAudioProcessorEditor::~HardClipperAudioProcessorEditor()
{
}

//==============================================================================
void HardClipperAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (25.0f);
    g.drawFittedText ("HardClipper", getLocalBounds(), juce::Justification::centredTop, 1);
}

void HardClipperAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    auto topMargin = 30;

    inputGainSlider.setBounds(50, 25, 75, 250);
    inputGainLabel.setBounds(50, 275, 50, 25);
    thresholdSlider.setBounds(150, 25, 75, 250);
    thresholdLabel.setBounds(150, 275, 50, 25);
    outputGainSlider.setBounds(250, 25, 75, 250);
    outputGainLabel.setBounds(250, 275, 50, 25);
}

void HardClipperAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    audioProcessor.inputGain = inputGainSlider.getValue();
    audioProcessor.threshold = thresholdSlider.getValue();
    audioProcessor.outputGain = outputGainSlider.getValue();
}