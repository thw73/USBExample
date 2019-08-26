package org.qtproject.usbexample;

import android.os.Bundle;


import org.qtproject.qt5.android.bindings.QtActivity;
import com.ftdi.j2xx.D2xxManager;
import com.ftdi.j2xx.FT_Device;



public class MyFTDIClass extends QtActivity
{


    private static MyFTDIClass m_instance;

    private static D2xxManager ftD2xx = null;
    private static FT_Device ftDev0 = null;
    private static FT_Device ftDev1 = null;



    public MyFTDIClass()
    {
        m_instance = this;
    }


    public static int initFTDI()
    {
        try
        {
            ftD2xx = D2xxManager.getInstance(m_instance);

        } catch (D2xxManager.D2xxException ex) {
            ex.printStackTrace();
            ftDev0.close();
            }

        int devCount = 0;
        devCount = ftD2xx.createDeviceInfoList(m_instance);

        if (devCount > 0)
        {
            int openIndex = 0;
            ftDev0 = ftD2xx.openByIndex(m_instance,openIndex); //Open Cannel A (device 0)

            int openIndex1 = 1;
            ftDev1 = ftD2xx.openByIndex(m_instance,openIndex1); //Open Cannel B (device )



                if (ftDev0.isOpen() == true)
                {

                    ftDev0.setBitMode((byte) 0, D2xxManager.FT_BITMODE_ASYNC_BITBANG); // 0x00: Device 0 (Channel A): all pins are input


                 }


                if (ftDev1.isOpen() == true)
                {

                 ftDev1.setBitMode((byte) 0xFF, D2xxManager.FT_BITMODE_ASYNC_BITBANG); // 0xff: Device 1 (Channel B): all pins are output


                }
        }

    return devCount;

    }




    public static short Read_USB()
    {


    short BitModeValue;


    BitModeValue = (short) (ftDev0.getBitMode() & 0x00ff); //Read value port D0 - D7


    return(BitModeValue);
    }


    public static void Write_USB(byte[] data)
    {

       ftDev1.write(data,1);

     }


}

