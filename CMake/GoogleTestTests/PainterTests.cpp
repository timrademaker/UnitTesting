#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Painter.h"

#include "ITurtle_Test.h"

/*
    Note: A mock function with bool return type will always return false
          A mock function with any other return type will always return 0
*/


using ::testing::AnyNumber;
using ::testing::AtLeast;
using ::testing::AtMost;
using ::testing::Between;
using ::testing::Exactly;
using ::testing::Return;
using ::testing::_;
using ::testing::Gt;
using ::testing::Lt;

using ::testing::Sequence;
using ::testing::InSequence;

using ::testing::NiceMock;
using ::testing::NaggyMock;
using ::testing::StrictMock;


TEST(PainterTest, CanDrawSomething)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    EXPECT_CALL(turtle, PenDown())
        .Times(AtLeast(1));

    EXPECT_CALL(turtle, Forward(_))
        .Times(AtLeast(1));

    EXPECT_CALL(turtle, Turn(_))
        .Times(AtLeast(1));

    EXPECT_CALL(turtle, PenUp())
        .Times(AtLeast(1));


    // Execute actions
    Painter p(turtle);
    EXPECT_TRUE(p.DrawCircle(0, 0, 10));
}

TEST(PainterTest, ExpectCallWithArguments)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    // GoTo will be called once, with X = 50 and Y = *
    EXPECT_CALL(turtle, GoTo(50, _))
        .Times(1);

    // GoTo will be called twice, with X = * and Y = 50
    EXPECT_CALL(turtle, GoTo(_, 50))
        .Times(2);

    // Execute actions
    // Note: For the sake of these examples, we're directly calling the functions.
    // You wouldn't do this in an actual test.
    turtle.GoTo(50, 0 );

    turtle.GoTo(0 , 50);
    turtle.GoTo(50, 50);
}


TEST(PainterTest, ExpectReturn)
{
    // Create mock object
    MockTurtle turtle;
    
    // Set expectations
    // GetY will be called once, and will return 100
    EXPECT_CALL(turtle, GetY())
        .Times(1)
        .WillOnce(Return(100));         // Return 100 once

    // GetX
    EXPECT_CALL(turtle, GetX())
        .Times(5)
        .WillOnce(Return(100))          // Return 100 once
        .WillOnce(Return(200))          // Return 100 once
        .WillRepeatedly(Return(300));   // Return 300 for the remaining calls


    // Execute actions
    ASSERT_EQ(turtle.GetY(), 100);

    ASSERT_EQ(turtle.GetX(), 100);
    ASSERT_EQ(turtle.GetX(), 200);
    ASSERT_EQ(turtle.GetX(), 300);
    ASSERT_EQ(turtle.GetX(), 300);
    ASSERT_EQ(turtle.GetX(), 300);
}

TEST(PainterTest, SequenceExample)
{
    // Create mock objects
    MockTurtle turtle;
    MockTurtle turtle2;

    // Set expectations
    InSequence seq;

    EXPECT_CALL(turtle, GetX())
        .Times(1);

    EXPECT_CALL(turtle2, GetX())
        .Times(1);

    EXPECT_CALL(turtle, GetY())
        .Times(1);
    

    // Execute actions
    // Any other function calls being made at any point don't affect the outcome of the sequence test
    // (but they will result in a warning for uninteresting function calls)
    turtle.GetX();
    turtle2.GetX();
    turtle.GetY();
}

TEST(PainterTest, SequenceFail)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    InSequence seq;

    EXPECT_CALL(turtle, GetX())
        .Times(1);

    EXPECT_CALL(turtle, GetY())
        .Times(1);


    // Execute actions
    // Actions are executed in an incorrect order
    turtle.GetY();
    turtle.GetX();
}

TEST(PainterTest, MultipleSequences)
{
    // Create mock objects
    MockTurtle turtle;
    MockTurtle turtle2;

    // Set expectations
    Sequence seq;
    Sequence seq2;

    EXPECT_CALL(turtle, GetX())
        .Times(1)
        .InSequence(seq, seq2);

    EXPECT_CALL(turtle, GetY())
        .Times(1)
        .InSequence(seq);

    EXPECT_CALL(turtle2, GetX())
        .Times(1)
        .InSequence(seq2);

    EXPECT_CALL(turtle, GoTo(_, _))
        .Times(1)
        .InSequence(seq);

    // Execute actions
    // Both sequences expect this call first
    turtle.GetX();

    // The remaining order of calls doesn't matter, as both calls are expected in a different sequence.
    // Of course, the in-sequence call order still matters.
    // Sequence 1
    turtle.GetY();
    turtle.GoTo(0, 0);

    // Sequence 2
    turtle2.GetX();
}

TEST(PainterTest, NoSequence)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    EXPECT_CALL(turtle, PenUp())
        .Times(2);

    EXPECT_CALL(turtle, PenDown())
        .Times(2);

    // Execute actions
    turtle.PenDown();
    turtle.PenUp();
    turtle.PenUp();
    turtle.PenDown();
}

TEST(PainterTest, StickyExpectations)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    EXPECT_CALL(turtle, GoTo(_, _))
        .Times(AnyNumber());

    EXPECT_CALL(turtle, GoTo(0, 0))
        .Times(2);

    // Execute actions
    turtle.GoTo(0, 0);
    turtle.GoTo(0, 0);

    turtle.GoTo(0, 0);       // Will cause the test to fail - GoTo(0, 0) is only expected to be called twice
}

TEST(PainterTest, NonStickyExpectations)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    EXPECT_CALL(turtle, GoTo(_, _))
        .Times(AnyNumber());

    EXPECT_CALL(turtle, GoTo(0, 0))
        .Times(2)
        .RetiresOnSaturation();

    // Execute actions
    turtle.GoTo(0, 0);
    turtle.GoTo(0, 0);

    turtle.GoTo(0, 0);       // Won't cause the test to fail - The expectation for GoTo(0, 0) to be called only twice has been retired
                             // Note that sequences don't have this issue, as expectations are automatically retired.
}


TEST(PainterTest, NiceMockExample)
{
    // Create mock object
    // NiceMock objects ignore all uninteresting calls
    NiceMock<MockTurtle> turtle;

    // Set expectations
    EXPECT_CALL(turtle, GoTo(_, _))
        .Times(1);

    // Execute actions
    turtle.GoTo(0, 0);

    // Make an uninteresting call
    turtle.Forward(1);
}

TEST(PainterTest, NaggyMockExample)
{
    // Create mock object
    // NaggyMock objects warn you if an uninteresting call is made
    NaggyMock<MockTurtle> turtle;

    // Set expectations
    EXPECT_CALL(turtle, GoTo(_, _))
        .Times(1);

    // Execute actions
    turtle.GoTo(0, 0);

    // Make an uninteresting call
    turtle.Forward(1);
}

TEST(PainterTest, StrictMockExample)
{
    // Create mock object
    // StrictMock objects fail the test if an uninteresting call is made
    StrictMock<MockTurtle> turtle;

    // Set expectations
    EXPECT_CALL(turtle, GoTo(_, _))
        .Times(1);

    // Execute actions
    turtle.GoTo(0, 0);

    // Make an uninteresting call
    turtle.Forward(1);
}

TEST(PainterTest, WillByDefaultExample)
{
    // Create mock object
    MockTurtle turtle;

    // Set (no) expectations
    ON_CALL(turtle, GetX())
        .WillByDefault(Return(100));

    // Set an expectation
    EXPECT_CALL(turtle, GetX())
        .Times(AtLeast(1))
        .WillOnce(Return(1));

    // GetX will return 1 once
    ASSERT_EQ(turtle.GetX(), 1);

    // Make an uninteresting call
    ASSERT_EQ(turtle.GetX(), 100);
}

TEST(PainterTest, DisallowUnexpectedCall)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    EXPECT_CALL(turtle, GetX())
        .Times(0);

    // Make an unexpected call
    turtle.GetX();
}

TEST(PainterTest, CardinalitiesExample)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    EXPECT_CALL(turtle, GetX())
        .Times(AnyNumber());

    EXPECT_CALL(turtle, GetY())
        .Times(AtLeast(1));

    EXPECT_CALL(turtle, PenDown())
        .Times(AtMost(2));

    EXPECT_CALL(turtle, PenUp())
        .Times(Between(1, 5));

    EXPECT_CALL(turtle, Forward(_))
        .Times(Between(1, 3));

    EXPECT_CALL(turtle, Turn(_))
        .Times(Exactly(3));

    // Execute actions
    for (std::size_t i = 0; i < 10; ++i)
    {
        // Any number of times
        turtle.GetX();
        // At least once
        turtle.GetY();
    }

    // At most twice
    turtle.PenDown();
    turtle.PenDown();
    // Between 1 and 5 times (inclusive)
    turtle.PenUp();
    
    // Between 1 and 3 times (inclusive)
    turtle.Forward(5);
    turtle.Forward(5);
    turtle.Forward(5);

    // Exactly 3 times
    turtle.Turn(1);
    turtle.Turn(1);
    turtle.Turn(1);
}

TEST(PainterTest, ExpectedArgumentNotExactly)
{
    // Create mock object
    MockTurtle turtle;

    // Set expectations
    EXPECT_CALL(turtle, Turn(Gt(40)))
        .Times(1);

    EXPECT_CALL(turtle, Forward(Lt(5)))
        .Times(1);

    // Execute actions
    turtle.Turn(45);

    turtle.Forward(4);
}