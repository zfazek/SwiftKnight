package com.ongroa.knight;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * Unit test for simple App.
 */
public class AppTest extends TestCase
{
    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public AppTest( String testName )
    {
        super( testName );
    }

    /**
     * @return the suite of tests being tested
     */
    public static Test suite()
    {
        return new TestSuite( AppTest.class );
    }

    public void testGetCoordinate()
    {
        App app = new App();
        assertEquals("", app.getCoordinate(0));
        assertEquals("a1", app.getCoordinate(21));
        assertEquals("h1", app.getCoordinate(28));
        assertEquals("a8", app.getCoordinate(91));
        assertEquals("h8", app.getCoordinate(98));
    }
    
    public void testGetPosition() {
        App app = new App();
        assertEquals(0, app.getPosition(null));
        assertEquals(0, app.getPosition(""));
        assertEquals(0, app.getPosition("a"));
        assertEquals(0, app.getPosition("aa"));
        assertEquals(0, app.getPosition("a11"));
        assertEquals(21, app.getPosition("A1"));
        assertEquals(21, app.getPosition("a1"));
        assertEquals(28, app.getPosition("a8"));
        assertEquals(91, app.getPosition("h1"));
        assertEquals(98, app.getPosition("h8"));
    }
}
