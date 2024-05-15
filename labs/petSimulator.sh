
##The most advanced pet simulator on the market
##"I thought it was actually my dog!"
echo "Would you like a dog, a cat, or a mouse?"
read pet
echo "On a scale of one to ten how talkative is your pet?"
read noiseLevel
case $pet in
	dog)
		echo
		i=1
		until ((i>noiseLevel))
		do
			echo "bark"
			((i++))
			done
	;;

	cat)
		echo
		for ((ii = 0; ii < $noiseLevel; ii++))
		do
			echo "meow"
			done
	;;

	mouse)
		echo
		i=noiseLevel
		while ((i>0))
		do
			echo "squeek"
			((i--))
			done
	;;
esac
