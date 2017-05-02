require 'rubygems'
require 'selenium-webdriver'

browser = Selenium::WebDriver.for :safari
browser.manage.window.maximize
wait = Selenium::WebDriver::Wait.new(:timeout => 10)
browser.get "https://es.pinterest.com/login/?referrer=home_page"
#Click SignUp
browser.find_element(:css,".FullPageSignup__signupToggle").click
sleep 3
#Email/Pass
browser.find_element(:css,"[type='email']").send_keys "painball36+21@gmail.com"
browser.find_element(:css,"[type='password']").send_keys "YdE-Epo-3fd-WHz"
browser.find_element(:css,".red.SignupButton.active").click
sleep 6
#Llenar Form
browser.find_element(:xpath,"/html/body/div[1]/div/div[1]/div/div/div/div/div/div[3]/div/form/fieldset[1]/input").send_keys "Ariel Lucien"
browser.find_element(:xpath,"/html/body/div[1]/div/div[1]/div/div/div/div/div/div[3]/div/form/fieldset[2]/input").send_keys "21"
browser.find_element(:css,"[name='gender']").click
browser.find_element(:css,"[type='submit']").click
sleep 10

begin #Aveces sale un anuncio de la app movil
	browser.find_element(:css,".noButtonStyles.active").click
	sleep 10
rescue
	puts "No Hubo anuncio"
end
#Seleccionar 5 intereses
sleep 1
interests = browser.find_elements(:css,".interestMaskAndWrapper")
interests[0].click
interests[1].click
interests[2].click
interests[3].click
interests[4].click
sleep 1
browser.find_element(:css,".Button.nuxModalPickerInterestButton").click
sleep 10 #Tarda un rato en crear la cuenta
#AQUI YA SE CREO LA CUENTA, IR AL POST Y ESCRIBIR ALGO
browser.get 'https://es.pinterest.com/pin/298011700317676477/'

browser.execute_script( %& document.querySelectorAll('.commentDropdownIcon.collapsed')[0].click(); & )
sleep 2
browser.find_element(:css,"textarea").send_keys "Nice"
browser.find_element(:css,".addComment").click
sleep 5
