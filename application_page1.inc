<?php
  require_once('CFsoap.php');
function application_form_page1($form_state) {

  $form = array();

  ahah_helper_register($form, $form_state);
  $states = get_sonis_drop_box("state");
  $countries = get_sonis_drop_box("country");

//
// Name
  $form['Name'] = array(
    '#type' => 'fieldset',
    '#title' => t('Name'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['Name']['preferred'] = array(
    '#type' => 'textfield',
    '#title' => t('Preferred Name or Nickname'),
    '#default_value' => $form_state['values']['first'],
    '#description' => "The name you would like us to refer to you by. For example, <em>Bob</em> if your first name is <em>Robert</em>.",
    '#maxlength' => 20,
  );
  $form['Name']['first'] = array(
    '#type' => 'textfield',
    '#title' => t('Legal First Name'),
    '#default_value' => $form_state['values']['first'],
    '#required' => TRUE,
    '#maxlength' => 20,
  );
  $form['Name']['middle'] = array(
    '#type' => 'textfield',
    '#title' => t('Middle Name'),
    '#default_value' => $form_state['values']['middle'],
    '#required' => FALSE,
    '#maxlength' => 20,
  );
  $form['Name']['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#default_value' => $form_state['values']['last'],
    '#required' => TRUE,
    '#maxlength' => 20,
  );

// Birthplace Information
  $form['Birthplace_Information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Birthplace Information'),
    '#prefix' => '<div id="birthplace-information-wrapper">', // This is our wrapper div.
    '#suffix' => '</div>',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['Birthplace_Information']['dateofbirth'] = array(
    '#type' => 'date',
    '#title' => t('Date of Birth'),
    '#default_value' => $form_state['values']['dateofbirth'],
     '#required' => TRUE,
  );
  $form['Birthplace_Information']['countryofbirth'] = array(
    '#type' => 'select',
    '#title' => t('Country of Birth'),
    '#default_value' => $form_state['values']['countryofbirth'],
    '#options' => $countries,
   '#ahah' => array(
     'path' => ahah_helper_path(array('Birthplace_Information')),
	   'wrapper' => 'birthplace-information-wrapper',
	   'method' => 'replace',
	   'event' => 'change',
	   'effect' => 'fade',
  	),
    '#required' => TRUE,
  );
  $form['Birthplace_Information']['update_countryofbirth'] = array(
    '#type' => 'submit',
    '#value' => t('Country of Birth'),
    // Note that we can simply use the generic submit callback provided by the
    // ahah_helper module here!
    // All it does, is set $form_state['rebuild'] = TRUE.
    '#submit' => array('ahah_helper_generic_submit'),
    // We set the 'no-js' class, which means this submit button will be hidden
    // automatically by Drupal if JS is enabled.
    '#attributes' => array('class' => 'no-js'),
  );

  if ($form_state['values']['countryofbirth'] == "" || $form_state['values']['countryofbirth'] == "UNITED STATES") {
    $form['Birthplace_Information']['cityofbirth'] = array(
      '#type' => 'textfield',
      '#title' => t('City of Birth'),
      '#default_value' => $form_state['values']['cityofbirth'],
       '#required' => TRUE,
    );
    $form['Birthplace_Information']['stateofbirth'] = array(
      '#type' => 'select',
      '#title' => t('State of Birth'),
      '#default_value' => $form_state['values']['stateofbirth'],
      '#options' => $states,
      '#required' => FALSE,
    );
    $form['Birthplace_Information']['ssn'] = array(
      '#type' => 'textfield',
      '#title' => t('Social Security Number'),
      '#default_value' => $form_state['values']['ssn'],
       '#required' => TRUE,
    );
  }
  else {
    $form['Birthplace_Information']['countryofcitizenship'] = array(
      '#type' => 'select',
      '#title' => t('Country of Citizenship'),
      '#default_value' => $form_state['values']['countryofbirth'],
    '#options' => $countries,
      '#required' => FALSE,
    );

    $form['Birthplace_Information']['aliennumber'] = array(
      '#type' => 'textfield',
      '#title' => t('Naturalized Citizen or Permanent Resident Number'),
      '#default_value' => $form_state['values']['aliennumber'],
      '#required' => TRUE,
    );
    $form['Birthplace_Information']['aliennumberapplied'] = array(
      '#type' => 'checkbox',
      '#title' => t('Permanent Resident Number applied for'),
      '#default_value' => $form_state['values']['aliennumberapplied'],
       '#required' => TRUE,
    );
    $form['Birthplace_Information']['visa'] = array(
      '#type' => 'select',
      '#title' => t('Current Visa Status'),
      '#default_value' => $form_state['values']['countryofbirth'],
      '#description' => "FHCHS is not currently accepting applicants requiring an F visa.",
    '#options' => array(
      'Ask Zoe' => t(':)'),
      'or Katie' => t('F2'),
      'AppliedFor' => t('Visa Applied For'),
    ),
      '#required' => FALSE,
    );
  }

// Contact Information
  $form['Contact Information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact Information'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['Contact Information']['countryofresidence'] = array(
    '#type' => 'select',
    '#title' => t('Country of Residence'),
    '#default_value' => $form_state['values']['countryofresidence'],
  '#options' => $countries,
    '#required' => FALSE,
  );
  $form['Contact Information']['streetaddress'] = array(
    '#type' => 'textfield',
    '#title' => t('Street Address'),
    '#default_value' => $form_state['values']['streetaddress'],
    '#required' => TRUE,
  );
  $form['Contact Information']['addresscity'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' => $form_state['values']['addresscity'],
    '#required' => TRUE,
  );
  $form['Contact Information']['addresscity'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' => $form_state['values']['addresscity'],
    '#required' => TRUE,
  );
  $form['Contact Information']['state'] = array(
    '#type' => 'select',
    '#title' => t('State'),
    '#default_value' => $form_state['values']['state'],
  '#options' => $states,
    '#required' => TRUE,
  );
  $form['Contact Information']['postalcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal Code'),
    '#default_value' => $form_state['values']['postalcode'],
    '#required' => TRUE,
	'#maxlength' => 10,
	'#size' => 10,
  );
  $form['Contact Information']['primaryphone'] = array(
    '#type' => 'textfield',
    '#title' => t('Primary Phone Number'),
    '#default_value' => $form_state['values']['primaryphone'],
    '#required' => TRUE,
	'#description' => "The first number we should dial when trying to reach you.",
  );
  $form['Contact Information']['alternatephone'] = array(
    '#type' => 'textfield',
    '#title' => t('Alternate Phone Number'),
    '#default_value' => $form_state['values']['alternatephone'],
    '#required' => FALSE,
    '#description' => "If we can't reach you at the first number, we'll try this one.",
  );
return ($form);

}
?>