require 'rubygems'
require 'selenium-webdriver'
#require 'watir'
#browser = Watir::Browser.new :firefox
#browser.close

browser = Selenium::WebDriver.for :safari
wait = Selenium::WebDriver::Wait.new(:timeout => 10)
browser.get "https://bit.ly/watir-example"

#Name
browser.find_element(:id, "entry_1000000").send_keys "prueba!"
#Story
browser.find_element(:id, "entry_1000001").send_keys "Una historia muy larga"
#Tools
browser.find_element(:id, "group_1000002_#{rand(1..2)}").click
#Language
max_langs = 3
to_click = (1..max_langs).to_a.sample( rand(0..max_langs) )
to_click.each { |x| browser.find_element(:id, "group_1000003_#{x}").click }
#SELECTS
dropDownMenu = browser.find_element(:id, "entry_1000004")
options = dropDownMenu.find_elements(:tag_name => "option")
raise "No hay 7 elementos en dropdown" unless options.size == 7
selected = options.sample
selected.click
puts selected.text
#Happy
browser.find_element(:id, "group_1000005_#{rand(1..5)}").click 
#OpenSource
browser.find_element(:id, "group_1000006_#{rand(1..5)}").click 
browser.find_element(:id, "group_1000007_#{rand(1..5)}").click
#Submit
browser.find_element(:name, "submit").click
#Nueva pagina
sleep 2

#w = wait.until { driver.find_element(:id => "gb_P") }
browser.quit
