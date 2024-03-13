/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class HardClipperAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    HardClipperAudioProcessorEditor(HardClipperAudioProcessor&);
    ~HardClipperAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    HardClipperAudioProcessor& audioProcessor;

    juce::Slider inputGainSlider;
    juce::Slider outputGainSlider;
    juce::Slider thresholdSlider;
    juce::Label inputGainLabel;
    juce::Label outputGainLabel;
    juce::Label thresholdLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HardClipperAudioProcessorEditor)
};
