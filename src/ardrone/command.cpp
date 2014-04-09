// -------------------------------------------------------------------------
// CV Drone (= OpenCV + AR.Drone)
// Copyright(C) 2013 puku0x
// https://github.com/puku0x/cvdrone
//
// This source file is part of CV Drone library.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of EITHER:
// (1) The GNU Lesser General Public License as published by the Free
//     Software Foundation; either version 2.1 of the License, or (at
//     your option) any later version. The text of the GNU Lesser
//     General Public License is included with this library in the
//     file cvdrone-license-LGPL.txt.
// (2) The BSD-style license that is included with this library in
//     the file cvdrone-license-BSD.txt.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the files
// cvdrone-license-LGPL.txt and cvdrone-license-BSD.txt for more details.
// -------------------------------------------------------------------------

#include "ardrone.h"

// --------------------------------------------------------------------------
// ARDrone::initCommand()
// Description  : Initialize AT command.
// Return value : SUCCESS: 1  FAILURE: 0
// --------------------------------------------------------------------------
int ARDrone::initCommand(void)
{
    // Open the IP address and port
    if (!sockCommand.open(ip, ARDRONE_AT_PORT)) {
        CVDRONE_ERROR("UDPSocket::open(port=%d) failed. (%s, %d)\n", ARDRONE_AT_PORT, __FILE__, __LINE__);
        return 0;
    }

    // AR.Drone 2.0
    if (version.major == ARDRONE_VERSION_2) {
        // Send undocumented command
        sockCommand.sendf("AT*PMODE=%d,%d\r", ++seq, 2);

        // Send undocumented command
        sockCommand.sendf("AT*MISC=%d,%d,%d,%d,%d\r", ++seq, 2, 20, 2000, 3000);

        // Send flat trim
        sockCommand.sendf("AT*FTRIM=%d,\r", ++seq);

        // Set the configuration IDs
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"custom:session_id\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID);
        msleep(100);
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"custom:profile_id\",\"%s\"\r", ++seq, ARDRONE_PROFILE_ID);
        msleep(100);
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"custom:application_id\",\"%s\"\r", ++seq, ARDRONE_APPLOCATION_ID);
        msleep(100);

        // Set maximum altitude
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"control:altitude_max\",\"%d\"\r", ++seq, 3000);
        msleep(100);

        // Disable bitrate control mode
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"video:bitrate_ctrl_mode\",\"0\"\r", ++seq);
        msleep(100);

        // Set video codec
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"video:video_codec\",\"%d\"\r", ++seq, 0x81);   // H264_360P_CODEC
        //sockCommand.sendf("AT*CONFIG=%d,\"video:video_codec\",\"%d\"\r", ++seq, 0x82); // MP4_360P_H264_720P_CODEC
        //sockCommand.sendf("AT*CONFIG=%d,\"video:video_codec\",\"%d\"\r", ++seq, 0x83); // H264_720P_CODEC
        //sockCommand.sendf("AT*CONFIG=%d,\"video:video_codec\",\"%d\"\r", ++seq, 0x88); // MP4_360P_H264_360P_CODEC
        msleep(100);

        // Set video channel to default
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"video:video_channel\",\"0\"\r", ++seq);
        msleep(100);

        // Disable USB recording
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"video:video_on_usb\",\"FALSE\"\r", ++seq);
        msleep(100);
    }
    // AR.Drone 1.0
    else {
        // Send undocumented command
        sockCommand.sendf("AT*PMODE=%d,%d\r", ++seq, 2);

        // Send undocumented command
        sockCommand.sendf("AT*MISC=%d,%d,%d,%d,%d\r", ++seq, 2, 20, 2000, 3000);

        // Send flat trim
        sockCommand.sendf("AT*FTRIM=%d,\r", ++seq);

        // Set maximum altitude
        sockCommand.sendf("AT*CONFIG=%d,\"control:altitude_max\",\"%d\"\r", ++seq, 3000);
        msleep(100);

        // Disable bitrate control mode
        sockCommand.sendf("AT*CONFIG=%d,\"video:bitrate_ctrl_mode\",\"0\"\r", ++seq);
        msleep(100);

		

        // Set video codec
        sockCommand.sendf("AT*CONFIG=%d,\"video:video_codec\",\"%d\"\r", ++seq, 0x20);   // UVLC_CODEC
        //sockCommand.sendf("AT*CONFIG=%d,\"video:video_codec\",\"%d\"\r", ++seq, 0x40); // P264_CODEC (not supported)
        msleep(100);
        
        // Set video channel to default
        sockCommand.sendf("AT*CONFIG=%d,\"video:video_channel\",\"0\"\r", ++seq);
        msleep(100);

		
    }

    // Disable outdoor mode
    setOutdoorMode(false);

    // Create a mutex
    mutexCommand = new pthread_mutex_t;
    pthread_mutex_init(mutexCommand, NULL);

    // Create a thread
    threadCommand = new pthread_t;
    if (pthread_create(threadCommand, NULL, runCommand, this) != 0) {
        CVDRONE_ERROR("pthread_create() was failed. (%s, %d)\n", __FILE__, __LINE__);
        return 0;
    }

    return 1;
}

// --------------------------------------------------------------------------
// ARDrone::loopCommand()
// Description  : Thread function for AT Command.
// Return value : SUCCESS:0
// --------------------------------------------------------------------------
void ARDrone::loopCommand(void)
{
    while (1) {
        // Reset Watch-Dog every 100ms
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*COMWDG=%d\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
        pthread_testcancel();
        msleep(100);
    }
}

// --------------------------------------------------------------------------
// ARDrone::takeoff()
// Description  : Take off the AR.Drone.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::takeoff(void)
{
    // Get the state
    if (mutexCommand) pthread_mutex_lock(mutexNavdata);
    int state = navdata.ardrone_state;
    if (mutexCommand) pthread_mutex_unlock(mutexNavdata);

    // If AR.Drone is in emergency, reset it
    if (state & ARDRONE_EMERGENCY_MASK) emergency();
    else {
        // Send take off
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*REF=%d,290718208\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
    }
}

// --------------------------------------------------------------------------
// ARDrone::landing()
// Description  : Land the AR.Drone.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::landing(void)
{
    // Get the state
    if (mutexCommand) pthread_mutex_lock(mutexNavdata);
    int state = navdata.ardrone_state;
    if (mutexCommand) pthread_mutex_unlock(mutexNavdata);

    // If AR.Drone is in emergency, reset it
    if (state & ARDRONE_EMERGENCY_MASK) emergency();
    else {
        // Send langding
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*REF=%d,290717696\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
    }
}

// --------------------------------------------------------------------------
// ARDrone::emergency()
// Description  : Emergency stop.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::emergency(void)
{
    // Send emergency
    if (mutexCommand) pthread_mutex_lock(mutexCommand);
    sockCommand.sendf("AT*REF=%d,290717952\r", ++seq);
    if (mutexCommand) pthread_mutex_unlock(mutexCommand);
}

// --------------------------------------------------------------------------
// ARDrone::move(X velocity[m/s], Y velocity[m/s], Rotational speed[rad/s])
// Description  : Move the AR.Drone in 2D plane.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::move(double vx, double vy, double vr)
{
    move3D(vx, vy, 0.0, vr);
}

// --------------------------------------------------------------------------
// ARDrone::move3D(X velocity[m/s], Y velocity[m/s], Z velocity[m/s], Rotational speed[rad/s])
// Description  : Move the AR.Drone in 3D space.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::move3D(double vx, double vy, double vz, double vr)
{
    // AR.Drone is flying
    if (!onGround()) {
        // Command velocities
        float v[4] = {-vy*0.2, -vx*0.2, vz*1.0, -vr*0.5};
        int mode = (fabs(v[0]) > 0.0 || fabs(v[1]) > 0.0 || fabs(v[2]) > 0.0 || fabs(v[3]) > 0.0);

        // Nomarization (-1.0 to +1.0)
        for (int i = 0; i < 4; i++) {
            if (fabs(v[i]) > 1.0) v[i] /= fabs(v[i]);
        }

        // Send a command
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*PCMD=%d,%d,%d,%d,%d,%d\r", ++seq, mode, *(int*)(&v[0]), *(int*)(&v[1]), *(int*)(&v[2]), *(int*)(&v[3]));
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
    }
}

// --------------------------------------------------------------------------
// ARDrone::setCamera(Camera channel)
// Description  : Change the camera channel.
//                AR.Drone1.0 supports 0, 1, 2, 3.
//                AR.Drone2.0 supports 0, 1.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::setCamera(int channel)
{
    // Enable mutex lock
    if (mutexCommand) pthread_mutex_lock(mutexCommand);

    // AR.Drone 2.0
    if (version.major == ARDRONE_VERSION_2) {
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        sockCommand.sendf("AT*CONFIG=%d,\"video:video_channel\",\"%d\"\r", ++seq, channel % 2);
    }
    // AR.Drone 1.0
    else {
        sockCommand.sendf("AT*CONFIG=%d,\"video:video_channel\",\"%d\"\r", ++seq, channel % 4);
    }

    // Disable mutex lock
    if (mutexCommand) pthread_mutex_unlock(mutexCommand);

    msleep(100);
}

// --------------------------------------------------------------------------
// ARDrone::setFlatTrim()
// Description  : Set a reference of the horizontal plane.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::setFlatTrim(void)
{
    if (onGround()) {
        // Send flat trim command
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*FTRIM=%d\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
    }
}

// --------------------------------------------------------------------------
// ARDrone::setCalibration(Device ID)
// Description  : Calibrate AR.Drone's magnetometer.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::setCalibration(int device)
{
    if (!onGround()) {
        // Send calibration command
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*CALIB=%d,%d\r", ++seq, device);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
    }
}

// --------------------------------------------------------------------------
// ARDrone::setAnimation(Flight animation ID, Timeout[ms])
// Description  : Run specified flight animation.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::setAnimation(int id, int timeout)
{
    // ID
    if (version.major == ARDRONE_VERSION_2) id = abs(id % ARDRONE_NB_ANIM_MAYDAY);
    else                                    id = abs(id % ARDRONE_ANIM_FLIP_AHEAD);

    // Default timeout
    if (timeout < 1) {
        const int default_timeout[ARDRONE_NB_ANIM_MAYDAY] = {1000, 1000, 1000, 1000, 1000, 1000, 5000, 5000, 2000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 15, 15, 15, 15};
        timeout = default_timeout[id];
    }

    // Send a command
    if (mutexCommand) pthread_mutex_lock(mutexCommand);
    sockCommand.sendf("AT*ANIM=%d,%d,%d\r", ++seq, id, timeout);
    if (mutexCommand) pthread_mutex_unlock(mutexCommand);
}

// --------------------------------------------------------------------------
// ARDrone::setLED(LED animation ID, Frequency[Hz], Duration[s])
// Description  : Run specified LED animation.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::setLED(int id, float freq, int duration)
{
    // ID
    id = abs(id % ARDRONE_NB_LED_ANIM_MAYDAY);

    // Default frequency
    if (freq <= 0.0) {
        float default_freq[ARDRONE_NB_LED_ANIM_MAYDAY] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
        freq = default_freq[id];
    }

    // Default frequency
    if (freq <= 0.0) {
        int default_duration[ARDRONE_NB_LED_ANIM_MAYDAY] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        duration = default_duration[id];
    }

    // Send a command
    if (mutexCommand) pthread_mutex_lock(mutexCommand);
    sockCommand.sendf("AT*LED=%d,%d,%d,%d\r", ++seq, id, *(int*)(&freq), duration);
    if (mutexCommand) pthread_mutex_unlock(mutexCommand);
}

// --------------------------------------------------------------------------
// ARDrone::startVideoRecord(Enable/Disable)
// Description  : Start or stop recording video.
//                This function is only for AR.Drone 2.0
//                You should set a USB key with > 100MB to your drone
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::setVideoRecord(bool activate)
{
    // AR.Drone 2.0
    if (version.major == ARDRONE_VERSION_2) {
        // Finalize video
        finalizeVideo();

        // Enable/Disable video recording
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        if (activate) sockCommand.sendf("AT*CONFIG=%d,\"video:video_on_usb\",\"TRUE\"\r",  ++seq);
        else          sockCommand.sendf("AT*CONFIG=%d,\"video:video_on_usb\",\"FALSE\"\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
        msleep(100);

        // Output video with MP4_360P_H264_720P_CODEC / H264_360P_CODEC
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        if (activate) sockCommand.sendf("AT*CONFIG=%d,\"video:video_codec\",\"%d\"\r", ++seq, 0x82);
        else          sockCommand.sendf("AT*CONFIG=%d,\"video:video_codec\",\"%d\"\r", ++seq, 0x81);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
        msleep(100);

        // Initialize video
        initVideo();
    }
}

// --------------------------------------------------------------------------
// ARDrone::setOutdoorMode(Enable/Disable)
// Description  : Set outdoor mode.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::setOutdoorMode(bool activate)
{
    // AR.Drone 2.0
    if (version.major == ARDRONE_VERSION_2) {
        // Enable/Disable outdoor mode
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        if (activate) sockCommand.sendf("AT*CONFIG=%d,\"control:outdoor\",\"TRUE\"\r",  ++seq);
        else          sockCommand.sendf("AT*CONFIG=%d,\"control:outdoor\",\"FALSE\"\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
        msleep(100);

        // Without/With shell
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", ++seq, ARDRONE_SESSION_ID, ARDRONE_PROFILE_ID, ARDRONE_APPLOCATION_ID);
        if (activate) sockCommand.sendf("AT*CONFIG=%d,\"control:flight_without_shell\",\"TRUE\"\r",  ++seq);
        else          sockCommand.sendf("AT*CONFIG=%d,\"control:flight_without_shell\",\"FALSE\"\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
        msleep(100);
    }
    // AR.Drone 1.0
    else {
        // Enable/Disable outdoor mode
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        if (activate) sockCommand.sendf("AT*CONFIG=%d,\"control:outdoor\",\"TRUE\"\r",  ++seq);
        else          sockCommand.sendf("AT*CONFIG=%d,\"control:outdoor\",\"FALSE\"\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
        msleep(100);

        // Without/With shell
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        if (activate) sockCommand.sendf("AT*CONFIG=%d,\"control:flight_without_shell\",\"TRUE\"\r",  ++seq);
        else          sockCommand.sendf("AT*CONFIG=%d,\"control:flight_without_shell\",\"FALSE\"\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
        msleep(100);
    }
}

// --------------------------------------------------------------------------
// ARDrone::resetWatchDog()
// Description  : Stop hovering.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::resetWatchDog(void)
{
    // Get the state
    if (mutexCommand) pthread_mutex_lock(mutexNavdata);
    int state = navdata.ardrone_state;
    if (mutexCommand) pthread_mutex_unlock(mutexNavdata);

    // If AR.Drone is in Watch-Dog, reset it
    if (state & ARDRONE_COM_WATCHDOG_MASK) {
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*COMWDG=%d\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
    }
}

// --------------------------------------------------------------------------
// ARDrone::resetEmergency()
// Description  : Disable the emergency lock.
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::resetEmergency(void)
{
    // Get the state
    if (mutexCommand) pthread_mutex_lock(mutexNavdata);
    int state = navdata.ardrone_state;
    if (mutexCommand) pthread_mutex_unlock(mutexNavdata);

    // If AR.Drone is in emergency, reset it
    if (state & ARDRONE_EMERGENCY_MASK) {
        if (mutexCommand) pthread_mutex_lock(mutexCommand);
        sockCommand.sendf("AT*REF=%d,290717952\r", ++seq);
        if (mutexCommand) pthread_mutex_unlock(mutexCommand);
    }
}

// --------------------------------------------------------------------------
// ARDrone::findCircle()
// Description  : Find a circle in the bottom image
// Return value : True if a circle is found, false elsewhere
// -------------------------------------------------------------------------
bool ARDrone::findCircle (IplImage* image)
{
	//Get the image of the bottom camera
	const cv::Mat image_bottom (image, cv::Rect(0, 0, 85, 70));

	//Convert image to gray
	cv::Mat image_bottom_gray;
    cv::cvtColor(image_bottom, image_bottom_gray, CV_BGR2GRAY);

	//Resize the image
	cv::resize(image_bottom_gray, image_bottom_gray,
		cv::Size( 0, 0 ), 3, 3);

	cv::medianBlur(image_bottom_gray, image_bottom_gray, 5);

	//Find circles
    cv::vector<cv::Vec3f> circles;
    cv::HoughCircles(image_bottom_gray, circles, CV_HOUGH_GRADIENT, 1, 50,
                 100, 30, 20, 100        );

	//Circles found
	if (!circles.empty()) 
		return true;

	//Not Found
	else 
		return false;
}

// --------------------------------------------------------------------------
// ARDrone::findLine()
// Description  : Find the most prominent line's offset and angle
// Return value : True if a line is found, false elsewhere
// --------------------------------------------------------------------------
bool ARDrone::findLine (const cv::Mat  imageBottom, double&  offsetPix, double&  angleDeg, const double principalPointU)
{
	// scale down
	double scaleFactor = 3;
	double thresholdFactor = 0.5;
	cv::Mat imageBottomScaled ;
	cv::resize(imageBottom, imageBottomScaled,
		cv::Size( 0, 0 ), scaleFactor, scaleFactor) ;

	//cv::imshow("Image Resize", imageBottomScaled);

	// convert to HSV and apply thresholds
	cv::Mat hsv ;
	cv::cvtColor(imageBottomScaled, hsv, CV_BGR2HSV ) ;

	// threshold
	cv::Mat orange, violet, red ;
	cv::inRange( hsv,
		cv::Scalar(   0,  64,  96 ),
		cv::Scalar(  20, 255, 255 ),
		orange                      ) ;
	cv::inRange( hsv,
		cv::Scalar( 160,  64,  96 ),
		cv::Scalar( 180, 255, 255 ),
		violet                      ) ;
	red = orange | violet ;

	// detect lines: 1px distance resolution, 1° angle resolution, 100 pixels in the original image required
	std::vector< cv::Vec2f > lines;
	cv::HoughLines(red, lines, 1.0, CV_PI / 180.0, 100 * thresholdFactor * thresholdFactor);
	
	if(!lines.empty()) 
	{
		// extract parameters
		float rho   = lines[0][0],
			theta = lines[0][1] ;  

		// convert to outside representation
		offsetPix = ( rho / cos( theta ) / scaleFactor) - principalPointU ;
		angleDeg  = theta * 180.0 / CV_PI ; if( angleDeg > 90.0 ) { angleDeg -= 180.0 ; }

		//Success
		return true;
	}

	// if no line found, leave values unchanged and return
	else return false;
}

// --------------------------------------------------------------------------
// ARDrone::followLine()
// Description  : Send command to the AR Drone according to the line position
// Return value : True if a line was found, false elsewhere
// --------------------------------------------------------------------------
bool ARDrone::followLine(IplImage* image)
{
	//Get the image of the bottom camera
	const cv::Mat image_bottom (image, cv::Rect(0, 0, 85, 70));

	//Useful parameters to move the drone
	double offsetPix = 0.0, angleDeg = 0.0;
	double vx = 0.0, vy = 0.0, vz = 0.0, vr = 0.0;

	const bool found = findLine(image_bottom, offsetPix, angleDeg, 43);

	//If a line was found in the image
	if (found)
	{
		//Ajust altitude
		if (getAltitude() > 1.1) 
			vz = -0.5;

		//Ajust angle
		if (angleDeg < -10 || angleDeg > 10)
		{
			//Turn left
			if (angleDeg < -10)
				vr = 0.5;

			//Turn right
			else 
				vr = -0.5;
		}

		//Ajust according the line offset
		else if (offsetPix < -20 || offsetPix > 20)
		{
			//Move left
			if (offsetPix < -20)
				vy = 0.25;

			//Move right
			else
				vy = -0.25;
		}

		//If no ajustment is necessary, move on !
		else  
			vx = 0.6;

		//Send the command
		move3D(vx, vy, vz, vr);

		//sucess
		return true;
	}

	//if no line was found, increase altitude to find a line
	else if (getAltitude() < 1.2)
		vz = 0.5;

	//Send the command
	move3D(vx, vy, vz, vr);

	//Fail
	return false;
}

// --------------------------------------------------------------------------
// ARDrone::detectFaces()
// Description  : Detect human faces in the front image
// Return value : True if a face was detected, false elsewhere.
// -------------------------------------------------------------------------
bool ARDrone::detectFaces(IplImage *image)
{
	// Load the classifier
	CvHaarClassifierCascade* cascade = (CvHaarClassifierCascade*)cvLoadHaarClassifierCascade("../../asset/haarcascade_frontalface_alt.xml", cvSize(24,24));
	
	CvMemStorage* storage = cvCreateMemStorage(0); 

	//Drop off the bottom image which could disturb the detection algorithm
	for (int i = 0; i < 72; i ++)
	{
		for (int j = 0; j < 87; j ++)
		{
			cv::Scalar scalar = cvGet2D(image, i, j);
			scalar[0] = 0;
			scalar[1] = 0;
			scalar[2] = 0;
			cvSet2D(image, i, j, scalar);
		}
	}

	//Resize the image
	IplImage* imageResized = cvCreateImage(cvSize((image->width)*1.5,(image->height)*1.5),image->depth,image->nChannels);

	cvResize(image, imageResized, CV_INTER_LINEAR);

	// Apply median filter to reduce noise
	cvSmooth(imageResized, imageResized, CV_MEDIAN,3);

	// Perform the face detection
	CvSeq *faces = cvHaarDetectObjects(imageResized, cascade, storage, 1.11, 3, CV_HAAR_DO_CANNY_PRUNING, cvSize(50,50), cvSize (300, 300)); 

	return faces->total;
}


// --------------------------------------------------------------------------
// ARDrone::finalizeCommand()
// Description  : Finalize AT command
// Return value : NONE
// --------------------------------------------------------------------------
void ARDrone::finalizeCommand(void)
{
    // Destroy the thread
    if (threadCommand) {
        pthread_cancel(*threadCommand);
        pthread_join(*threadCommand, NULL);
        delete threadCommand;
        threadCommand = NULL;
    }

    // Delete the mutex
    if (mutexCommand) {
        pthread_mutex_destroy(mutexCommand);
        delete mutexCommand;
        mutexCommand = NULL;
    }

    // Close the socket
    sockCommand.close();
}